"""
Find the lowest common ancestor of 2 tree nodes
"""

# -*- encoding: utf-8 *-*


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def construct_tree(self):
        self.root = Node(8)
        self.root.left = Node(3)
        self.root.left.left = Node(1)
        self.root.left.right = Node(6)
        self.root.left.right.left = Node(4)
        self.root.left.right.right = Node(7)
        self.root.right = Node(12)
        self.root.right.left = Node(11)
        self.root.right.right = Node(15)
        self.root.right.right.left = Node(14)

    def print_level_order_traversal(self, root):
        if root is None:
            return None

        queue = []
        queue.append(root)
        print()
        while(len(queue) > 0):
            count = len(queue)
            while(count > 0):
                curr_node = queue.pop(0)
                print(curr_node.data, end=" ")
                if curr_node.left:
                    queue.append(curr_node.left)
                if curr_node.right:
                    queue.append(curr_node.right)
                count -= 1
            print()

    def find_LCA_util(self, root, val1, val1_height, val2, val2_height, dist, level):
        temp = Node(None)
        if root is None:
            return None

        if root.data == val1:
            val1_height[0] = level
            temp = root

        if root.data == val2:
            val2_height[0] = level
            temp = root

        if val1_height[0] is not -1 and val2_height[0] is not -1 and temp.data:
            return temp

        lca_left = self.find_LCA_util(root.left, val1, val1_height, val2, val2_height, dist, level + 1)
        lca_right = self.find_LCA_util(root.right, val1, val1_height, val2, val2_height, dist, level + 1)

        if temp.data:
            return temp

        if lca_left is None and lca_right is None:
            return None
        elif lca_left is not None and lca_right is not None:
            dist[0] = val1_height[0] + val2_height[0] - (2 * level)
            return root
        elif lca_left is not None:
            return lca_left
        else:
            return lca_right

    def node_distance(self, root, val1, val2):
        if root is None:
            return

        val1_height = [-1]
        val2_height = [-1]
        level = 0
        dist = [-1]
        lca = self.find_LCA_util(root, val1, val1_height, val2, val2_height, dist, level)
        if lca is None or val1_height[0] is -1 or val2_height[0] is -1:
            print("Cannot find LCA")

        print("LCA = ", lca.data)
        print("Dist between ", val1, " and ", val2, " is ", dist[0])


def main():
    tree = Tree()
    tree.construct_tree()
    # tree.print_level_order_traversal(tree.root)
    tree.node_distance(tree.root, 14, 11)
    return


if __name__ == '__main__':
    main()
