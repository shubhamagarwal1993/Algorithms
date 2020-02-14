"""
Given an array of random numbers. Find longest increasing subsequence (LIS) in the array.

E.g.
For [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
return [0, 2, 6, 9, 11, 15]

Time Complexity: O(nlogn)
"""

# -*- encoding: utf-8 *-*


def get_ceil_index(input, left, right, key):
    """
    Binary search
    """
    while right - left > 1:
        m = left + int((right - left) / 2)
        if input[m] >= key:
            right = m
        else:
            left = m

    return right


def get_longest_increasing_subsequence(input):
    if len(input) == 0:
        return []

    # Only maintain ends of longest increasing sequences
    tail = []

    # Maintain elements of LIS
    prev_index_list = [-1] * len(input)

    lis_length = 1

    tail.append(input[0])
    # [3 ,  8,  4, 12,  2, 10,  6]
    # [-1, -1, -1, -1, -1, -1, -1]

    for i in range(1, len(input)):

        #  New smallest value
        if input[i] < tail[0]:
            tail[0] = input[i]

        # New biggest value
        elif input[i] > tail[lis_length - 1]:
            lis_length += 1
            tail.append(input[i])

        # Value lies within range
        else:
            """
            Possible positions input[i] can end in:
            - becomes end candidate of an existing subsequence
            - throw away larger elements in all lis to make room for upcoming greater elements
            """
            ceil_index = get_ceil_index(tail, -1, lis_length - 1, input[i])
            tail[ceil_index] = input[i]

    print(tail)

    return lis_length


def main():
    input = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
    # input = [4, 5, 6, 7, 8, 9, 10, 11, 1, 2, 3]
    print("longest increasing subsequence - ", get_longest_increasing_subsequence(input))
    return


if __name__ == '__main__':
    main()

