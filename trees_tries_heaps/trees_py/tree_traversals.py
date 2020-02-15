"""
Different methods of traversing a tree - inorder, preorder, and postorder
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

    #           1
    #          / \
    #         /   \
    #        /     \
    #       /       \
    #      /         \
    #    10           3
    #   /  \         / \
    #  /    \       /   \
    # 4      6     2     9
    #  \    / \   / \   / \
    #  30  0   5 21  8 7  11

    def construct_tree(self):
        self.root = Node(1)
        self.root.left = Node(10)
        self.root.left.left = Node(4)
        self.root.left.left.right = Node(30)
        self.root.left.right = Node(6)
        self.root.left.right.left = Node(0)
        self.root.left.right.right = Node(5)
        self.root.right = Node(3)
        self.root.right.left = Node(2)
        self.root.right.left.left = Node(21)
        self.root.right.left.right = Node(8)
        self.root.right.right = Node(9)
        self.root.right.right.left = Node(7)
        self.root.right.right.right = Node(11)

    def height(self, root):
        if root is None:
            return 0
        left_height = self.height(root.left)
        right_height = self.height(root.right)

        if left_height > right_height:
            return left_height + 1
        else:
            return right_height + 1

    def in_order_traversal(self, root):
        if root is None:
            return
        self.in_order_traversal(root.left)
        print(root.data, end=" ")
        self.in_order_traversal(root.right)
        return

    def pre_order_traversal(self, root):
        if root is None:
            return
        print(root.data, end=" ")
        self.pre_order_traversal(root.left)
        self.pre_order_traversal(root.right)

    def post_order_traversal(self, root):
        if root is None:
            return
        self.post_order_traversal(root.left)
        self.post_order_traversal(root.right)
        print(root.data, end=" ")

    def print_given_level(self, root, level):
        """
            Given root of tree, print a level of the tree
        """
        if root is None:
            return

        if level == 1:
            print(root.data, end=" ")
        elif level > 1:
            self.print_given_level(root.left, level - 1)
            self.print_given_level(root.right, level - 1)

    def print_level_order_iterative(self, root):
        if root is None:
            return
        height = self.height(root)
        print()
        for i in range(1, height+1):
            self.print_given_level(root, i)
            print()

    def level_order_traversal(self, root):
        """
        Breadth-first traversal, print out the data by level
        """
        if root is None:
            return

        queue = []
        queue.append(root)
        print()
        while(len(queue) > 0):
            count = len(queue)
            while(count > 0):
                count -= 1
                curr_node = queue.pop(0)
                print(curr_node.data, end=" ")
                if curr_node.left:
                    queue.append(curr_node.left)
                if curr_node.right:
                    queue.append(curr_node.right)
            print()

    def level_order_traversal_reverse(self, root):
        """
        Breadth-first traversal, print out the data by level
        """
        if root is None:
            return

        queue = []
        queue.append(root)
        curr_pointer = 0
        total_nodes = self.get_node_count(root) - 1
        while(total_nodes > 0):
            count = len(queue)
            while(count > 0):
                count -= 1
                total_nodes -= 1
                curr_node = queue[curr_pointer]
                if curr_node.left:
                    queue.append(curr_node.left)
                    curr_pointer += 1
                if curr_node.right:
                    queue.append(curr_node.right)
                    curr_pointer += 1
            line_break_node = Node("new line")
            queue.append(line_break_node)

        print()
        for i in range(len(queue)):
            print(queue[i].data, end=" ")
        print()

    def get_node_count(self, root):
        if root is None:
            return 0

        return 1 + self.get_node_count(root.left) + self.get_node_count(root.right)


def main():
    tree = Tree()
    tree.construct_tree()

    print("in order traversal: ", end=" ")
    tree.in_order_traversal(tree.root)
    print()

    print("preorder traversal: ", end=" ")
    tree.pre_order_traversal(tree.root)
    print()

    print("postorder traversal: ", end=" ")
    tree.post_order_traversal(tree.root)
    print()

    print("level order traversal iterative", end=" ")
    tree.print_level_order_iterative(tree.root)
    print()

    print("total nodes in tree - ", tree.get_node_count(tree.root))
    print()

    print("level order traversal", end=" ")
    tree.level_order_traversal(tree.root)
    print()

    print("reverse level order traversal", end=" ")
    tree.level_order_traversal_reverse(tree.root)
    print()
    return

if __name__ == '__main__':
    main()
