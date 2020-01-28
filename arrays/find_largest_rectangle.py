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
                print(test_matrix[i][j], end=" ")

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
    find_rectangle(matrix, row, col)


if __name__ == '__main__':
    main()

