"""
unsorted array of integers
Find the number of subarrays having sum exactly equal to a given number k

Examples:

Input : arr[] = {10, 2, -2, -20, 10}, k = -10
Output : 3
Subarrays: arr[0...3], arr[1...4], arr[3..4] have sum exactly equal to -10.

Input : arr[] = {9, 4, 20, 3, 10, 5}, k = 33
Output : 2
Subarrays : arr[0...2], arr[2...4] have sum exactly equal to 33.
"""

# -*- encoding: utf-8 *-*


def findSubArrays(input, k):

    current_sum = 0
    prevSum = {}
    indexDict = [-1]*len(input)
    total = 0
    start_idx = 0

    for idx in range(len(input)):
        current_sum += input[idx]

        # If subarray is found
        if current_sum == k:
            indexDict[start_idx] = idx
            start_idx += 1
            total += 1

        # This is how much we exceed k by
        # current_sum exceeds given k by current_sum - k
        extra_sum = current_sum - k

        # Check if we have seen this
        if extra_sum in prevSum:
            total += prevSum[extra_sum]
            for sum_idx in range(prevSum[extra_sum]):
                indexDict[start_idx] = idx
            start_idx += 1

        # Update the dictionary
        if current_sum in prevSum:
            prevSum[current_sum] = prevSum[current_sum] + 1
        else:
            prevSum[current_sum] = 1

    print("Total - ", total)
    print("Index - ", indexDict)
    return


def main():
    input = [10, 2, -2, -20, 10]
    k = -10
    findSubArrays(input, k)


if __name__ == '__main__':
    main()

