"""
Remove duplicates from a single linked list
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

    def print_linked_list_with_loop(self, curr):
        if curr is None:
            return

        for i in range(9):
            print(curr.data, end=' ')
            curr = curr.next
        print()

    def detect_loop(self, curr):
        if curr is None:
            return

        slow_runner = curr
        fast_runner = curr

        while(fast_runner is not None and fast_runner.next is not None):
            fast_runner = fast_runner.next.next
            slow_runner = slow_runner.next

            if fast_runner == slow_runner:
                print("Found collision at node", slow_runner.data)
                break

        return


def main():
    linked_list = Linked_list()
    linked_list.curr = linked_list.append_node(linked_list.curr, 1)
    linked_list.append_node(linked_list.curr, 2)
    linked_list.append_node(linked_list.curr, 3)
    linked_list.append_node(linked_list.curr, 4)
    linked_list.append_node(linked_list.curr, 5)
    linked_list.append_node(linked_list.curr, 6)
    linked_list.append_node(linked_list.curr, 7)
    linked_list.append_node(linked_list.curr, 8)
    # Point 8 to 5
    linked_list.curr.next.next.next.next.next.next.next.next = linked_list.curr.next.next.next.next

    linked_list.print_linked_list_with_loop(linked_list.curr)
    linked_list.detect_loop(linked_list.curr)
    # linked_list.remove_duplicates(linked_list.curr)
    # linked_list.print_linked_list(linked_list.curr)
    return


if __name__ == '__main__':
    main()

