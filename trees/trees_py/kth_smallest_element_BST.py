"""
    Find the kth smallest element in a BST
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

    def kth_smallest_element(self, root, k_list):
        if root is None:
            return

        self.kth_smallest_element(root.left, k_list)
        if k_list[0] == 1:
            print(root.data)
            k_list[0] -= 1
            return
        k_list[0] -= 1
        self.kth_smallest_element(root.right, k_list)
        return

    def get_node_count(self, root):
        if root is None:
            return 0

        return 1 + self.get_node_count(root.left) + self.get_node_count(root.right)


def main():
    tree = Tree()
    tree.construct_tree()
    tree.kth_smallest_element(tree.root, [5])
    return


if __name__ == '__main__':
    main()
