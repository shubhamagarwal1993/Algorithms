"""
Implement a min heap

Operations:
  - Insert in a min heap
  - Remove from a min heap
  - Validate a min heap
  - Heapify up
  - Heapify down

Properties of a min heap:
  - A binary tree that is complete
  - The data contained in each node is less than (or equal to) the data in that node's children

Construction / insert in a min heap:
  - Use an array to store a min heap
  - Store the root in position 0
  - place it in next available position in tree so it stays complete
    - Compare the new element with its parent. If the new element is smaller, than swap it with its parent
    - Continue this process until either:
      - The new element’s parent is smaller than or equal to the new element
      - The new element reaches the root (index 0 of the array)

Finding elements in min heap, given element curr_index
  - left_child_index = (2 * curr_index) + 1
  - right_child_index = (2 * curr_index) + 2
  - Parent: position curr_index/2

Remove from a min heap:
  - Place the root element in a variable to return later
  - Remove the last element in the deepest level and move it to the root
  - While the moved element has a value greater than at least one of its children, swap this value with the smaller-valued child
  - Return the original root that was saved

Efficiency of min heaps assuming N nodes:
  - Min heap has log2(N+1) levels
  - Insert: Since the insert swaps at most once per level, the order of complexity of insert is O(log N)
  - Remove: Since the remove swaps at most once per level, the order of complexity of remove is also O(log N)

Max Heap or Priority Queue is the same as min heap with bigger elements that children
"""

# -*- encoding: utf-8 *-*

import math


class MinHeap:
    def __init__(self):
        self.min_heap = []

    def print_min_heap(self, min_heap):
        if len(min_heap) == 0:
            return

        height = int(math.log2(len(min_heap))) + 1

        nodes_on_level = 0

        for i in range(len(min_heap)):
            # For each index, calculate level
            level = math.floor(math.log2(i+1))
            spaces = 2**(height - level + 1)
            nodes_on_level += 1

            # Print the spaces
            for j in range(spaces):
                print(" ", end=" ")
            print(min_heap[i], end=" ")

            # Check for line break each level has that many nodes
            if nodes_on_level >= (2**level):
                nodes_on_level = 0
                print()

        print()
        return

    def heapify_up(self, min_heap):
        curr_index = len(min_heap) - 1
        parent_index = int((curr_index - 1)/2)

        while curr_index != 0 and min_heap[parent_index] > min_heap[curr_index]:
            temp_val = min_heap[curr_index]
            min_heap[curr_index] = min_heap[parent_index]
            min_heap[parent_index] = temp_val

    def heapify_down(self, min_heap):
        curr_index = 0
        left_child_index = (2 * curr_index) + 1
        right_child_index = (2 * curr_index) + 2

        # Heapify down left tree
        while curr_index < len(min_heap) and min_heap[left_child_index] is not None and\
                min_heap[left_child_index] < min_heap[curr_index]:
                temp_val = min_heap[curr_index]
                min_heap[curr_index] = min_heap[left_child_index]
                min_heap[left_child_index] = temp_val

        # Heapify down right tree
        while curr_index < len(min_heap) and min_heap[right_child_index] is not None and\
                min_heap[right_child_index] < min_heap[curr_index]:
                temp_val = min_heap[curr_index]
                min_heap[curr_index] = min_heap[right_child_index]
                min_heap[right_child_index] = temp_val

    def insert_min_heap(self, min_heap, val):
        """
        Add element to end of heap and heapify up
        """
        min_heap.append(val)
        self.heapify_up(min_heap)
        return

    def delete_min_heap(self, min_heap):
        """
        Remove the root of the min_heap
        """
        if len(min_heap) == 0:
            return

        if len(min_heap) == 1:
            min_heap.pop(0)

        # Replace first element with last element and remove last element
        min_heap[0] = min_heap[len(min_heap) - 1]
        min_heap.pop(-1)

        self.heapify_down(min_heap)
        return


def main():
    min_heap = MinHeap()

    # Insert nodes
    min_heap.insert_min_heap(min_heap.min_heap, 1)
    min_heap.insert_min_heap(min_heap.min_heap, 2)
    min_heap.insert_min_heap(min_heap.min_heap, 3)
    min_heap.insert_min_heap(min_heap.min_heap, 5)
    min_heap.insert_min_heap(min_heap.min_heap, 6)
    min_heap.insert_min_heap(min_heap.min_heap, 7)
    min_heap.insert_min_heap(min_heap.min_heap, 4)
    min_heap.print_min_heap(min_heap.min_heap)

    # Delete nodes
    min_heap.delete_min_heap(min_heap.min_heap)
    min_heap.print_min_heap(min_heap.min_heap)
    return


if __name__ == '__main__':
    main()
