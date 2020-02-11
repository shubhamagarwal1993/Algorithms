"""
Given a matrix, find all possible paths from from start to finish
1s in the maze denotes barriers (dangerous cells),

E.g.
[[0, 1, 1, 1, 1, 1],
 [0, 1, 0, 0, 0, 0],
 [0, 1, 0, 1, 1, 0],
 [0, 1, 0, 0, 1, 0],
 [0, 1, 1, 0, 1, 0],
 [0, 0, 0, 0, 1, 0]]

"""

# *-* encoding: utf-8 -*-

import copy


def valid(maze, maze_sol, row_len, col_len, row_idx, col_idx):
    # out of bounds
    if row_idx < 0 or row_idx >= row_len:
        return False

    # out of bounds
    if col_idx < 0 or col_idx >= col_len:
        return False

    # Check if valid cell, only cells with 0 value are traversable
    if maze[row_idx][col_idx] != 0:
        return False

    # Check if already visited
    if maze_sol[row_idx][col_idx] != 0:
        return False

    return True


def find_path_sol(maze, row_len, col_len, maze_sol, row_idx, col_idx):

    if row_idx == row_len - 1 and col_idx == col_len - 1:
        maze_sol[row_idx][col_idx] = 2
        return True

    if valid(maze, maze_sol, row_len, col_len, row_idx, col_idx):
        maze_sol[row_idx][col_idx] = 2

        if find_path_sol(maze, row_len, col_len, maze_sol, row_idx + 1, col_idx):
            return True

        if find_path_sol(maze, row_len, col_len, maze_sol, row_idx - 1, col_idx):
            return True

        if find_path_sol(maze, row_len, col_len, maze_sol, row_idx, col_idx + 1):
            return True

        if find_path_sol(maze, row_len, col_len, maze_sol, row_idx, col_idx - 1):
            return True

        maze_sol[row_idx][col_idx] = 0
        return False

    return False


def print_maze(maze, row_len, col_len):
    for i in range(row_len):
        for j in range(col_len):
            print("{}".format(maze[i][j]), end=" ")
        print()
    return


def find_path(maze, row_len, col_len):
    maze_sol = copy.deepcopy(maze)
    find_path_sol(maze, row_len, col_len, maze_sol, 0, 0)
    print_maze(maze_sol, row_len, col_len)
    return


def main():
    maze = [[0, 1, 1, 1, 1, 1],
            [0, 1, 0, 0, 0, 0],
            [0, 1, 0, 1, 1, 0],
            [0, 1, 0, 0, 1, 0],
            [0, 1, 1, 0, 1, 0],
            [0, 0, 0, 0, 1, 0]]

    find_path(maze, 6, 6)
    return


if __name__ == '__main__':
    main()

