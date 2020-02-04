"""
Given an unsorted array, sort it using merge sort

There can be three ways of sorting with merge sort
 - recursively
 - using iterative loops
 - in place

E.g.
For [2, 7, 4, 3, 5, 1, 3] return [1, 2, 3, 3, 4, 5, 7]
"""

# -*- encoding: utf-8 *-*

import math


def merge(input, left, mid, right):
    return


def merge_sort_recursive(input, left, right):
    """
    Finding time complexity:
        T(n) = T(n/2) + T(n/2) + O(n)
        T(0) = 0
                n
          n/2      n/2
       n/4  n/4  n/4  n/4

        sum of each level = n
        value of each node = n/(2^l)
        n/(2^l) = 2 at last level. Thus n = 2^l => l = logn base 2
        Total work = height of tree * sum of each level => logn * n => O(nlogn)
    """
    if left < right:
        mid = math.floor((left + right) / 2)
        merge_sort_recursive(input, left, mid)
        merge_sort_recursive(input, mid + 1, right)

        merge(input, left, mid, right)
    return


def main():

    # Recursive merge sort
    input = [2, 1, 7, 4, 3, 4, 1, 3]
    left_index = 0
    right_index = len(input) - 1
    merge_sort_recursive(input, left_index, right_index)


if __name__ == '__main__':
    main()

