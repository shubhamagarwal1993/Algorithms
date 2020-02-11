"""
Check if a given tree is a BST
"""

# -*- encoding: utf-8 *-*

import math
import sys
import functools


class Node:
    """
    Holds a node of the tree
    """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def print_node(self):
        print(self.data)


class Tree:
    """
    Holds the definition of the tree
    """

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
        return self.root

    def print_tree(self, root):
        if root is None:
            return
        root.print_node()
        self.print_tree(root.left)
        self.print_tree(root.right)
        return

    def height(self, root):
        if root is None:
            return 0

        # Compute the height of each subtree
        left_height = self.height(root.left)
        right_height = self.height(root.right)

        # Use the larger one
        if left_height > right_height:
            return left_height + 1
        else:
            return right_height + 1

    def print_given_level(self, root, level):
        return

        # Print nodes at a given level
        if root is None:
            return

        if level == 1:
            print(root.data, " ")
        elif level > 1:
            print_given_level(root.left, level-1)
            print_given_level(root.right, level-1)

    def print_tree_level_order(self, root):
        tree_height = self.height(root)
        for i in range(1, tree_height + 1):
            self.print_given_level(root, i)

    def check_BST(self, root, min, min_char, max, max_char):
        if root is None:
            return True

        if (min_char is True and root.data < min) or (max_char is True and root.data > max):
            return False

        return self.check_BST(root.left, min, min_char, root.data, False) and\
            self.check_BST(root.right, root.data, False, max, max_char)


def main():
    tree = Tree()
    tree.construct_tree()
    # tree.print_tree(tree.root)
    # tree.print_tree_level_order(tree.root)

    # Check if tree is BST
    # if tree.check_BST(tree.root, 0, False, 0, False):
    #    print("This is a BST")
    # else:
    #    print("This is not a BST")
    # return

if __name__ == '__main__':
    main()
