"""
Compare 2 trees
 - Check if they are equal
 - Check if one is a subtree of another
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

    def compare_trees(self, node1, node2):
        if node1 is None and node2 is None:
            return True
        if node1 is None or node2 is None:
            return False
        return (node1.data == node2.data) and self.compare_trees(node1.left, node2.left) and\
            self.compare_trees(node1.right, node2.right)

    def subtree(self, node1, node2):
        if node2 is None:
            return True

        if node1 is None:
            return False

        if node1.data == node2.data:
            return self.subtree(node1.left, node2.left) and self.subtree(node1.right, node2.right)
        else:
            return self.subtree(node1.left, node2) or self.subtree(node1.right, node2)


class Tree1(Tree):
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


class Tree2(Tree):
    #     11
    #     / \
    #    /   \
    #   9    13

    def __init__(self):
        self.root = None

    def construct_tree(self):
        self.root = Node(11)
        self.root.left = Node(9)
        self.root.right = Node(13)
        return


def main():

    tree = Tree()
    tree.construct_tree()

    tree1 = Tree1()
    tree1.construct_tree()

    tree2 = Tree2()
    tree2.construct_tree()

    print("Trees are identical - ", end=" ")
    print(tree1.compare_trees(tree1.root, tree2.root))
    print()

    tree1.in_order_traversal(tree1.root)
    print()
    tree2.in_order_traversal(tree2.root)
    print()

    print("Tree2 is subtree of tree1 - ", end=" ")
    print(tree.subtree(tree1.root, tree2.root))
    print()

    return

if __name__ == '__main__':
    main()
