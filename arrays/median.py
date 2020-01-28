"""
Find median when given one or two arrays
List can have integers in any order

E.g.
median([0, 2, 5, 6, 8, 9, 9]) == 6
median([0, 0, 0, 0, 4, 4, 6, 8]) == 2

"""

# -*- encoding: utf-8 *-*

import heapq

class MaxHeapComp(object):
    def __init__(self, val):
        self.val = val

    def __lt__(self, other):
        return self.val > other.val

    def __eq__(self, other):
        return self.val == other.val

    def __str__(self):
        return str(self.val)

class MinHeap():
    def __init__(self):
        self.heap = []

    def heap_push(self, val):
        heapq.heappush(self.heap, val)

    def heap_pop(self):
        return heapq.heappop(self.heap)

    def __getitem__(self, idx):
        return self.heap[idx]

    def __len__(self):
        return len(self.heap)

class MaxHeap(MinHeap):
    def heap_push(self, val):
        heapq.heappush(self.heap, MaxHeapComp(val))

    def heap_pop(self):
        return heapq.heappop(self.heap).val

    def __getitem__(self, idx):
        return self.heap[idx].val

def median_single_list(input):
    if not input:
        return

    min_heap = MinHeap()
    max_heap = MaxHeap()

    # Testing max heap
    for idx in range(len(input)):
        # Odd numbers
        # if idx % 2 == 0:
        max_heap.heap_push(input[idx])

    return -1

def main():
    # Single list
    print(median_single_list([0, 9, 5, 6, 8, 9, 2]))

    return

if __name__ == '__main__':
    main()
