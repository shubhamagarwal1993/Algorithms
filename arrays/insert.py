"""
...
"""

# -*- encoding: utf-8 *-*


def insert_sorted(arr, left, right, val):
    if arr is None:
        return arr

    mid_index = int((left + right) / 2)
    mid_val = arr[mid_index]

    # Insert on the left side
    if mid_val > val:
        if mid_index > 0 and arr[mid_index - 1] < val:
            arr = arr[:mid_index] + [val] + arr[mid_index:]
            return arr
        else:
            arr = insert_sorted(arr, left, mid_index, val)
            return arr
    else:
        if mid_index < len(arr) - 1 and arr[mid_index + 1] > val:
            arr = arr[:mid_index + 1] + [val] + arr[mid_index + 1:]
            return arr
        else:
            arr = insert_sorted(arr, mid_index, right, val)
            return arr
    return arr


def main():
    arr = [1, 3, 4, 5, 6, 7, 8, 9, 10]

    print(arr)

    val = 2
    left = 0
    right = len(arr) - 1
    arr = insert_sorted(arr, left, right, val)

    print(arr)
    return

if __name__ == '__main__':
    main()

