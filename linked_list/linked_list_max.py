"""
Find max value in linked list recursively
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
            print(curr.data, end='')
            curr = curr.next
        print()

    def find_max(self, curr):
        if curr is None:
            return

        if curr.next is None:
            return curr.data

        curr_data = curr.data

        max_data = self.find_max(curr.next)
        if curr_data > max_data:
            max_data = curr_data
        return max_data

        return None


def main():
    linked_list = Linked_list()
    linked_list.curr = linked_list.append_node(linked_list.curr, 1)
    linked_list.append_node(linked_list.curr, 2)
    linked_list.append_node(linked_list.curr, 3)
    linked_list.append_node(linked_list.curr, 4)
    linked_list.print_linked_list(linked_list.curr)
    print(linked_list.find_max(linked_list.curr))
    return


if __name__ == '__main__':
    main()

