"""
linked list
"""

# *-* encoding: utf-8 -*-

import copy


class Node():
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class LinkedList():
    def __init__(self):
        self.root = None
        return

    def construct_linked_list(self):
        curr_node = self.root

        curr_node = Node(1)
        curr_node.next = Node(2)
        curr_node.next.next = Node(3)
        curr_node.next.next.next = Node(4)
        curr_node.next.next.next.next = Node(5)
        curr_node.next.next.next.next.next = Node(3)

        self.root = curr_node

    def print(self):
        curr_node = self.root
        while(curr_node is not None):
            print(curr_node.data, end=" ")
            curr_node = curr_node.next
        print()

    def reverse(self):
        prev = None
        curr = self.root
        next = curr.next

        while(next is not None):
            curr.next = prev
            prev = curr
            curr = next
            next = curr.next
        curr.next = prev

        self.root = curr
        return

    def remove_duplicates(self):
        linked_list_set = set()

        curr = self.root
        prev = None

        while(curr is not None):
            if curr.data in linked_list_set:
                prev.next = curr.next
                if prev.next is not None:
                    curr = prev.next
                else:
                    curr = None
            else:
                linked_list_set.add(curr.data)
                prev = curr
                curr = curr.next

        return


def main():
    linked_list = LinkedList()
    linked_list.construct_linked_list()
    linked_list.print()

    # Reverse linked list
    linked_list.reverse()
    linked_list.print()

    # Remove duplicates from linked list
    linked_list.remove_duplicates()
    linked_list.print()

    return

if __name__ == '__main__':
    main()

