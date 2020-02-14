"""
Remove a node from a singly-linked list when only given the pointer to the node
"""

# -*- encoding: utf-8 *-*


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Linked_list:
    def __init__(self):
        self.curr = None

    def append_node(self, curr, val):
        if curr is None:
            curr = Node(val)
            return curr
        else:
            new_node = Node(val)

            # Reach the last node
            while(curr.next is not None):
                curr = curr.next

            curr.next = new_node
            return curr

    def print_linked_list(self, curr):
        if curr is None:
            return

        while(curr is not None):
            print(curr.data, end=' ')
            curr = curr.next
        print()

    def delete_node(self, curr, val):
        if curr is None:
            return

        """
        get a pointer to the node - this is for the sake of the question
        """
        node_to_delete = curr
        while(node_to_delete is not None and node_to_delete.data != val):
            node_to_delete = node_to_delete.next
        if node_to_delete is None:
            print("Cannot find", val, "in linked list")
            return

        """
        Cases:
        Case 1: Node to delete is curr / root
        Case 2: Node to delete is not curr / root
        """
        if curr == node_to_delete:
            print("inside root del case")
            curr = curr.next
            node_to_delete.next = None
            node_to_delete = None
            # Necessary step since curr is a temp address that will not be returned
            self.curr = curr
            return

        """
        Cont Case 2:
          - Loop till you find node to delete
          - if next is not null
            - copy over the next value and delete the next node
          - if next is null
            - loop over till in node before node to delete
            - delete next node
        """
        if node_to_delete.next is not None:
            node_to_delete.data = node_to_delete.next.data
            temp_node = node_to_delete.next
            node_to_delete.next = node_to_delete.next.next
            temp_node.next = None
            temp_node = None
        else:
            temp_node = curr
            while(temp_node.next != node_to_delete):
                temp_node = temp_node.next
            node_to_delete = None
            temp_node.next = None
        return


def main():
    linked_list = Linked_list()
    linked_list.curr = linked_list.append_node(linked_list.curr, 1)
    linked_list.append_node(linked_list.curr, 2)
    linked_list.append_node(linked_list.curr, 3)
    linked_list.append_node(linked_list.curr, 4)
    linked_list.print_linked_list(linked_list.curr)
    linked_list.delete_node(linked_list.curr, 4)
    linked_list.print_linked_list(linked_list.curr)
    return


if __name__ == '__main__':
    main()

