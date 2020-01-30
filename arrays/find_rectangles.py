"""
Given matrix find bottom right corner and width of rectangle
0 and invalid cells, other numbers are valid cells

E.g.
[[0, 0, 0, 0, 0],
 [0, 1, 1, 1, 0],
 [0, 1, 1, 1, 0],
 [0, 1, 1, 1, 0],
 [0, 1, 1, 1, 0],
 [0, 1, 1, 1, 0],
 [1, 1, 1, 1, 0]
]
bottom right corner is 6, 3 and width of rectangle is 3
"""

# -*- encoding: utf-8 *-*

from __future__ import print_function
import copy

def find_rectangle(matrix, row, col):

    test_matrix = copy.deepcopy(matrix)

    for i in range(1, row):
        for j in range(1, col):
            if matrix[i][j] == 0:
                test_matrix[i][j] = 0
            else:
                test_matrix[i][j] = min(test_matrix[i-1][j], test_matrix[i][j-1], test_matrix[i-1][j-1]) + 1

    for i in range(row):
        for j in range(col):
            if j == col-1:
                print(test_matrix[i][j])
            else:
                #print(test_matrix[i][j], end = " ")
                continue

    # find max number in 2d array and its coordinates
    max_row_index = -1
    max_col_index = -1
    max_sum = 0

    for i in range(row):
        for j in range(col):
            if test_matrix[i][j] >= max_sum:
                max_sum = test_matrix[i][j]
                max_row_index = i
                max_col_index = j

    # print out largest rectangle
    print("bottom right corner: row = ", max_row_index, ", col = ", max_col_index)
    print("width = ", max_sum)
    print("find height by going up on bottom left corner")

    return

def find_inner_rectangle(input, top_left, row_len, col_len):
    bottom_right = top_left

    for row_idx in range(top_left[0], row_len):
        if input[row_idx][top_left[1]] == 0:
            input[row_idx][top_left[1]] = 9
            bottom_right = (row_idx, top_left[1])
        else:
            break

    for col_idx in range(top_left[1] + 1, col_len):
        if input[bottom_right[0]][col_idx] == 0:
            input[bottom_right[0]][col_idx] = 9
            bottom_right = (bottom_right[0], col_idx)
        else:
            break

    # We now have the top left, and bottom right. Make that part unuseable
    for row_idx in range(top_left[0], bottom_right[0] + 1):
        for col_idx in range(top_left[1], bottom_right[1] + 1):
            input[row_idx][col_idx] = 9

    return bottom_right

def find_all_rectangles(input, row_len, col_len):
    top_left = (-1, -1)
    bottom_right = (-1, -1)

    res = []

    # print the input
    for row_idx in range(row_len):
        for col_idx in range(col_len):
            print(input[row_idx][col_idx], end=" ")
        print()

    for row_idx in range(row_len):
        for col_idx in range(col_len):
            if(input[row_idx][col_idx] == 0):
                top_left = (row_idx, col_idx)
                bottom_right = find_inner_rectangle(input, top_left, row_len, col_len)
                res.append((top_left, bottom_right))
                top_left = (-1, -1)
                bottom_right = (-1, -1)

    # print the input
    print()
    for row_idx in range(row_len):
        for col_idx in range(col_len):
            print(input[row_idx][col_idx], end=" ")
        print()

    return res

def main():
    row = 7
    col = 5
    matrix = [[0, 0, 0, 0, 0],
              [0, 1, 1, 1, 0],
              [0, 1, 1, 1, 0],
              [0, 1, 1, 1, 0],
              [0, 1, 1, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0]
              ]
    # find_rectangle(matrix, row, col)

    input = [[1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 1, 1, 1, 1],
             [1, 1, 1, 0, 0, 0, 1],
             [1, 0, 1, 0, 0, 0, 1],
             [1, 0, 1, 1, 1, 1, 1],
             [1, 0, 1, 0, 0, 0, 0],
             [1, 1, 1, 0, 0, 0, 0],
             [1, 0, 1, 0, 1, 1, 0]
            ]
    res = find_all_rectangles(input, 8, 7)
    for coordinate in res:
        print(coordinate)


if __name__ == '__main__':
    main()

