"""
Merge Intervals

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6]

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping
"""

def merge_intervals(input):
    delete_arr = []
    for idx in range(1, len(input)):
        prev = input[idx - 1]
        curr = input[idx]

        # If previous end is more than current beginning, modify prev to be total range
        if prev[1] >= curr[0]:
            prev[1] = curr[1]
            delete_arr.append(idx)

    for idx in range(len(delete_arr) - 1, -1, -1):
        input = input[:delete_arr[idx]] + input[delete_arr[idx] + 1:]

    return input

def main():
    input = [[1,3],[2,6],[8,10],[15,18]]
    output = merge_intervals(input)
    print("input: {}\noutput: {}".format(input, output))

    input = [[1,4],[4,5]]
    output = merge_intervals(input)
    print("input: {}\noutput: {}".format(input, output))
    return

if __name__ == '__main__':
    main()
