"""
Print the left view of the tree

E.g.
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
     /   \
    8     9

Would be 1 2 4 8
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def construct_tree(self):
        self.root = Node(1)
        self.root.left = Node(2)
        self.root.left.left = Node(4)
        self.root.left.right = Node(5)
        self.root.left.right.left = Node(8)
        self.root.right = Node(3)
        self.root.right.left = Node(6)
        self.root.right.left.right = Node(9)
        self.root.right.right = Node(7)

    def level_order_traversal(self, root):
        if root is None:
            return

        queue = [root]
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

    def left_view(self, root, level, max_level):
        if root is None:
            return

        if level > max_level[0]:
            print(root.data)
            max_level[0] = level
        self.left_view(root.left, level+1, max_level)
        self.left_view(root.right, level+1, max_level)


def main():
    tree = Tree()
    tree.construct_tree()

    print("level order traversal")
    tree.level_order_traversal(tree.root)
    print()

    print("left view of tree")
    tree.left_view(tree.root, 1, [0])
    print()

    return


if __name__ == '__main__':
    main()
