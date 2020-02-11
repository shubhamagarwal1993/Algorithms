"""
Find the 2nd largest element in a BST

The largest element lies on the right most node
The 2nd largest element lies on the left of the right most element

You can do an inOrder traversal and keep the last largest element
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

    def in_order_traversal(self, root):
        if root is None:
            return
        self.in_order_traversal(root.left)
        print(root.data, end=" ")
        self.in_order_traversal(root.right)

    def get_node_count(self, root):
        if root is None:
            return 0
        return 1 + self.get_node_count(root.left) + self.get_node_count(root.right)

    def right_most_node(self, root):
        if root is None:
            return
        while(root.right):
            root = root.right
        return root

    def second_largest_element(self, root):
        if (root is None) or (root.left is None and root.right is None):
            return None

        curr_node = root
        while curr_node:
            # If tree does not have a right subtree, find element in left subtree
            if curr_node.left and root.right is None:
                return self.right_most_node(curr_node.left)

            if curr_node.right and curr_node.right.left is None and curr_node.right.right is None:
                return curr_node

            curr_node = curr_node.right

        return


def main():
    tree = Tree()
    tree.construct_tree()

    print("in order traversal: ", end=" ")
    tree.in_order_traversal(tree.root)
    print()

    print("total nodes in tree - ", tree.get_node_count(tree.root))
    print()

    print("right most node in tree", end=" ")
    right_most_node = tree.right_most_node(tree.root)
    if right_most_node:
        print(right_most_node.data)
    else:
        print("Cannot find right most node in tree")
    print()

    print("2nd largest element in tree", end=" ")
    second_largest_element = tree.second_largest_element(tree.root)
    if second_largest_element:
        print(second_largest_element.data)
    print()
    return

if __name__ == '__main__':
    main()
