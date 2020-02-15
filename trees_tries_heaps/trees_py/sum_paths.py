"""
    Given binary tree, each node contains an integer value

    list all paths that sum to given target value
    path can only go from parent to children
"""

# -*- encoding: utf-8 *-*


class Node():
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data


class Tree():
    def __init__(self):
        self.root = None

    #           3
    #          / \
    #         /   \
    #        /     \
    #       /       \
    #      /         \
    #     2          4
    #   /  \         / \
    #  /    \       /   \
    # 1      5     9     1
    #  \    / \   / \   / \
    #   2  4   6 8  3  2  10
    def construct_tree(self):
        self.root = Node(3)

        self.root.left = Node(2)
        self.root.right = Node(4)

        self.root.left.left = Node(1)
        self.root.left.right = Node(5)
        self.root.right.left = Node(9)
        self.root.right.right = Node(1)

        self.root.left.left.right = Node(2)
        self.root.left.right.left = Node(4)
        self.root.left.right.right = Node(6)
        self.root.right.left.left = Node(8)
        self.root.right.left.right = Node(3)
        self.root.right.right.left = Node(2)
        self.root.right.right.right = Node(10)
        return

    def in_order_traversal(self, root):
        if root is None:
            return

        self.in_order_traversal(root.left)
        print(root.data, end=" ")
        self.in_order_traversal(root.right)

    def find_sum_paths_util(self, root, sum_list, path):
        if root is None:
            return

        path.append(root.data)

        self.find_sum_paths_util(root.left, sum_list, path)
        self.find_sum_paths_util(root.right, sum_list, path)

        if sum(path) == sum_list[0]:
            print(path)

        path.pop(-1)
        return

    def find_sum_paths(self, root, sum):
        if root is None:
            return

        self.find_sum_paths_util(root, [sum], [])
        self.find_sum_paths(root.left, sum)
        self.find_sum_paths(root.right, sum)
        return


def main():
    tree = Tree()
    tree.construct_tree()

    tree.in_order_traversal(tree.root)
    print()

    tree.find_sum_paths(tree.root, 9)
    return

if __name__ == '__main__':
    main()
