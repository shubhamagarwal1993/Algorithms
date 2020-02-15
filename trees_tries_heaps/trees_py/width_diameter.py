"""
The Diameter of a tree (sometimes called the width) is the number of nodes on the longest
path between two end nodes

The width at a level is the number of nodes on a level
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

    #           7
    #          / \
    #         /   \
    #        /     \
    #       /       \
    #      /         \
    #     3          11
    #   /  \         / \
    #  /    \       /   \
    # 1      5     9    13
    #  \    / \   / \   / \
    #   2  4   6 8  10 12 14
    def construct_tree(self):
        self.root = Node(7)
        self.root.left = Node(3)
        self.root.left.left = Node(1)
        self.root.left.left.right = Node(2)
        self.root.left.right = Node(5)
        self.root.left.right.left = Node(4)
        self.root.left.right.right = Node(6)
        self.root.right = Node(11)
        self.root.right.left = Node(9)
        self.root.right.left.left = Node(8)
        self.root.right.left.right = Node(10)
        self.root.right.right = Node(13)
        self.root.right.right.left = Node(12)
        self.root.right.right.right = Node(14)

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

    def diameter(self, root, max_dist):
        if root is None:
            return 0

        left = self.diameter(root.left, max_dist)
        right = self.diameter(root.right, max_dist)

        if left + right + 1 > max_dist[0]:
            max_dist[0] = left + right + 1

        return max(left, right) + 1

    def get_width_at_level(self, root, level):
        if root is None:
            return 0

        if level == 1:
            return 1

        return self.get_width_at_level(root.left, level - 1) + self.get_width_at_level(root.right, level - 1)

    def max_width_util(self, root, width_by_level, level):
        if root is None:
            return

        if len(width_by_level) < level:
            width_by_level.append(1)
        else:
            width_by_level[level - 1] += 1

        self.max_width_util(root.left, width_by_level, level + 1)
        self.max_width_util(root.right, width_by_level, level + 1)
        return

    def max_width(self, root):
        width_by_level = []
        level = 1
        self.max_width_util(root, width_by_level, level)
        max_width = 0
        max_width_level = 0
        for i in range(len(width_by_level)):
            if width_by_level[i] > max_width:
                max_width = width_by_level[i]
                max_width_level = i + 1
        print("Max width of tree is", max_width, " at level", max_width_level)
        return


def main():
    tree = Tree()
    tree.construct_tree()
    tree.print_level_order_traversal(tree.root)
    print()

    max = [0]
    print("Diamter - ", tree.diameter(tree.root, max))

    level = 4
    width = tree.get_width_at_level(tree.root, level)
    print("Width at level ", level, "is ", width)

    tree.max_width(tree.root)
    return

if __name__ == '__main__':
    main()
