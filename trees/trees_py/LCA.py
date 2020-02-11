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

    def find_LCA_util(self, root, val1_exists, val1, val2_exists, val2):
        temp = Node(None)
        if root is None:
            return None

        if root.data == val1:
            val1_exists[0] = True
            temp = root

        if root.data == val2:
            val2_exists[0] = True
            temp = root

        if val1_exists[0] and val2_exists[0] and temp.data:
            return temp

        lca_left = self.find_LCA_util(root.left, val1_exists, val1, val2_exists, val2)
        lca_right = self.find_LCA_util(root.right, val1_exists, val1, val2_exists, val2)

        if temp.data:
            return temp

        if not lca_left and not lca_right:
            return None
        elif lca_left and lca_right:
            return root
        elif lca_left:
            return lca_left
        else:
            return lca_right

    def find_LCA(self, root, val1, val2):
        if root is None:
            return

        val1_exists = [False]
        val2_exists = [False]
        lca = self.find_LCA_util(root, val1_exists, val1, val2_exists, val2)
        if val1_exists[0] and val2_exists[0]:
            print("LCA - ", lca.data)
        elif not val1_exists[0] and not val2_exists[0]:
            print(val1, ", and ", val2, " does not exist")
        elif val2_exists[0]:
            print(val1, " does not exist")
        else:
            print(val2, " does not exist")


def main():
    tree = Tree()
    tree.construct_tree()
    # tree.print_level_order_traversal(tree.root)
    tree.find_LCA(tree.root, 14, 11)
    return


if __name__ == '__main__':
    main()
