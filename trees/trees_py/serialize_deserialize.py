"""
Convert a tree into string and back into a tree

Serialize function will flatten a tree into a string
Deserialize will construct a tree from a string

The string format can be <in order; pre order>
"""

# -*- encoding: utf-8 *-*

import copy


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

    def in_order(self, root):
        if root is None:
            return
        self.in_order(root.left)
        print(root.data, end=" ")
        self.in_order(root.right)

    def in_order_traversal_list(self, root, in_order_list):
        if root is None:
            return
        self.in_order_traversal_list(root.left, in_order_list)
        in_order_list.append(root.data)
        self.in_order_traversal_list(root.right, in_order_list)

    def pre_order_traversal_list(self, root, pre_order_list):
        if root is None:
            return
        pre_order_list.append(root.data)
        self.pre_order_traversal_list(root.left, pre_order_list)
        self.in_order_traversal_list(root.right, pre_order_list)

    def get_node_count(self, root):
        if root is None:
            return 0
        return 1 + self.get_node_count(root.left) + self.get_node_count(root.right)

    def serialize(self, root):
        if root is None:
            return ""

        # Use an array since it is mutable but a string is not
        in_order_list = []
        self.in_order_traversal_list(root, in_order_list)

        pre_order_list = []
        self.pre_order_traversal_list(root, pre_order_list)

        return in_order_list + pre_order_list

    def deserialize(self, in_pre_order_list):
        in_order_left = 0
        in_order_right = int(len(in_pre_order_list)/2) - 1
        pre_order_index = [int(len(in_pre_order_list)/2)]
        # new_tree = Tree()
        new_root = None
        new_root = self.deserialize_util(new_root, in_pre_order_list, len(in_pre_order_list), in_order_left, in_order_right, pre_order_index)

        new_tree = Tree()
        new_tree.root = new_root
        return new_tree

    def deserialize_util(self, new_root, in_pre_order_list, len_in_pre_order_list, in_order_left, in_order_right, pre_order_index):
        """
        pre_order_index is the current root
        the left and right node is found on either side of the pre_order node value in in_order
        """
        if in_order_left > in_order_right or pre_order_index[0] >= len_in_pre_order_list:
            return None

        root_data = copy.deepcopy(in_pre_order_list[pre_order_index[0]])
        new_root = Node(root_data)
        pre_order_index[0] += 1

        # Find data in in_order
        k = -1
        for i in range(in_order_left, in_order_right + 1):
            if in_pre_order_list[i] == root_data:
                k = i
                break

        new_root.left = self.deserialize_util(new_root.left, in_pre_order_list, len_in_pre_order_list, in_order_left, k - 1, pre_order_index)
        new_root.right = self.deserialize_util(new_root.right, in_pre_order_list, len_in_pre_order_list, k + 1, in_order_right, pre_order_index)
        return new_root


def main():

    tree = Tree()
    tree.construct_tree()
    in_pre_order_list = tree.serialize(tree.root)

    new_tree = tree.deserialize(in_pre_order_list)
    print("in_order tree: ", end=" ")
    new_tree.in_order(new_tree.root)
    print()

    return

if __name__ == '__main__':
    main()
