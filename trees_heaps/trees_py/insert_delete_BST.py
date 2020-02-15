"""
Find the lowest common ancestor of 2 tree nodes
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

    def in_order(self, root):
        if root is None:
            return
        self.in_order(root.left)
        print(root.data, end=" ")
        self.in_order(root.right)

    def insert_BST(self, root, val):
        if root is None:
            root = Node(val)
            return root

        if val > root.data and root.right is None:
            root.right = Node(val)
            return root
        elif val < root.data and root.left is None:
            root.left = Node(val)
            return root

        if val < root.data:
            self.insert_BST(root.left, val)
        else:
            self.insert_BST(root.right, val)

        return root

    def insert_lowest_level(self, root, val):
        if root is None:
            root = Node(val)
            return root

        queue = []
        queue.append(root)
        while(len(queue) > 0):
            curr_node = queue.pop(0)
            if curr_node.left is None:
                curr_node.left = Node(val)
                return root
            elif curr_node.right is None:
                curr_node.right = Node(val)
                return root
            queue.append(root.left)
            queue.append(root.right)
        return root

    def get_in_order_successor(self, root):
        """
        Give the node for which to find in_order successor
        First find in the right
        """
        if root is None:
            return None

        while(root.left is not None):
            root = root.left
        return root

    def delete_node_util(self, root, val):
        """
            Root is not the node to be deleted

            # - find node to be deleted in left subtree with a front runner
            # - find node to be deleted in right subtree with a front runner
            # - on finding the node to deleted, there are 4 cases:
            #     - Node with no children:
            #         - Can be deleted without any problem
            #     - Node with both children:
            #         - Find the minimum node in the right subtree (in_order successor)
            #         - Swap the data of root and in_order successor.
            #         - The node to be deleted is now a leaf node
            #         - Find and delete this leaf node
            #     - Node with left child
            #         Remove the node and join parent and child of node to be deleted
            #     - Node with right child
            #         Remove the node and join parent and child of node to be deleted
        """
        temp_node = root.left
        if temp_node is not None and temp_node.data == val:
            if temp_node.left is None and temp_node.right is None:
                temp_node = None
                root.left = None
            elif temp_node.right is not None:
                in_order_successor = self.get_in_order_successor(temp_node.right)
                temp_node.data = in_order_successor.data
                in_order_successor.data = val
                self.delete_node_util(temp_node, val)
            else:
                in_order_successor = self.get_in_order_successor(temp_node.left)
                temp_node.data = in_order_successor.data
                in_order_successor.data = val
                self.delete_node_util(temp_node, val)
            return root

        temp_node = root.right
        if temp_node is not None and temp_node.data == val:
            if temp_node.left is None and temp_node.right is None:
                temp_node = None
                root.right = None
            elif temp_node.right is not None:
                in_order_successor = self.get_in_order_successor(temp_node.right)
                temp_node.data = in_order_successor.data
                in_order_successor.data = val
                self.delete_node_util(temp_node, val)
            else:
                in_order_successor = self.get_in_order_successor(temp_node.left)
                temp_node.data = in_order_successor.data
                in_order_successor.data = val
                self.delete_node_util(temp_node, val)
            return root

        if val < root.data:
            root.left = self.delete_node_util(root.left, val)
        elif val > root.data:
            root.right = self.delete_node_util(root.right, val)

        return root

    def delete_node(self, root, val):
        """
        Deleting a node from a BST

        Case 1: root is the node to be deleted
            Case 1: Root has no children
                make root None and return
            Case 2: Root has right subtree
                - Find in_order successor in right subtree, make root val as in_order successor
                - case 2 in right subtree of root
            Case 3: Root has left subtree
                - Find in_order successor in left subtree, make root val as in_order successor
                - case 2 in left subtree of root

        Case 2: root is not the node to be deleted
            - find node to be deleted in left subtree with a front runner
            - find node to be deleted in right subtree with a front runner
            - on finding the node to deleted, there are 4 cases:
                - Node with no children:
                    - Can be deleted without any problem
                - Node with both children:
                    - Find the minimum node in the right subtree (in_order successor)
                    - Swap the data of root and in_order successor.
                    - The node to be deleted is now a leaf node
                    - Find and delete this leaf node
                - Node with left child
                    Remove the node and join parent and child of node to be deleted
                - Node with right child
                    Remove the node and join parent and child of node to be deleted
        """
        if root is None:
            return

        # If root is the node to be deleted
        if root.data == val:
            if root.left is None and root.right is None:
                root = None
                return root
            elif root.right is not None:
                in_order_successor = self.get_in_order_successor(root.right)
                root.data = in_order_successor.data
                root.right = self.delete_node_util(root.right, in_order_successor.data)
                return root
            else:
                in_order_successor = self.get_in_order_successor(root.left)
                root.data = in_order_successor.data
                root.left = self.delete_node_util(root.leaf, in_order_successor.data)
                return root
        else:
            return self.delete_node_util(root, val)


def main():
    tree = Tree()
    tree.root = tree.insert_BST(tree.root, 50)
    tree.insert_BST(tree.root, 30)
    tree.insert_BST(tree.root, 20)
    tree.insert_BST(tree.root, 40)
    tree.insert_BST(tree.root, 70)
    tree.insert_BST(tree.root, 80)

    tree.in_order(tree.root)
    print()

    # insert a node at lowerst possible level in the tree
    tree.insert_lowest_level(tree.root, 60)

    tree.print_level_order_traversal(tree.root)
    print()

    # Delete a node from BST
    val = 60
    tree.delete_node(tree.root, val)
    tree.print_level_order_traversal(tree.root)
    print()
    return


if __name__ == '__main__':
    main()
