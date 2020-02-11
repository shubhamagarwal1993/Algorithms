"""
Find the mirror of the BST
"""

# -*- encoding:utf-8 *-*


class Node():
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


class Tree():
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
        self.root.right = Node(11)

        self.root.left.left = Node(1)
        self.root.left.right = Node(5)
        self.root.right.left = Node(9)
        self.root.right.right = Node(13)

        self.root.left.left.right = Node(2)
        self.root.left.right.left = Node(4)
        self.root.left.right.right = Node(6)
        self.root.right.left.left = Node(8)
        self.root.right.left.right = Node(10)
        self.root.right.right.left = Node(12)
        self.root.right.right.right = Node(14)
        return

    def mirror(self, root):
        if root is None:
            return
        return

    def print_level_order(self, root):
        return


def main():
    tree = Tree()
    tree.construct_tree()
    tree.print_level_order(root)
    # tree.mirror(tree.root)
    return


if __name__ == '__main__':
    main()
