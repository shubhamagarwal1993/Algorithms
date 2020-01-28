"""
Simple binary search
"""

# *-* encoding: utf-8 -*-


def bin_search(arr, key, l, r):
    if l > r:
        return -1

    mid_index = int((l + r)/2)

    if arr[mid_index] == key:
        return mid_index
    if arr[mid_index] > key:
        return bin_search(arr, key, mid_index, r)
    if arr[mid_index] < key:
        return bin_search(arr, key, l, mid_index)
    return 0


def main():
    arr = [5, 8, 3, 2, 7]
    print(bin_search(arr, 2, 0, 5))
    return

if __name__ == '__main__':
    main()

