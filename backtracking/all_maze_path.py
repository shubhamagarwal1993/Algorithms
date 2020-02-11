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

# -*- encoding: utf-8 *-*

import copy


def valid_cell(maze, row_size, col_size, r_idx, c_idx, path_maze):
    """
        check if we can move to a particular cell
    """
    # invalid row index
    if r_idx < 0 or r_idx >= row_size:
        return False

    # inavlid col index
    if c_idx < 0 or c_idx >= col_size:
        return False

    # cannot move to this cell
    if maze[r_idx][c_idx] != 0:
        return False

    # have already been through this cell
    if path_maze[r_idx][c_idx] != 0:
        return False

    return True


def any_path_in_maze(maze, row_size, col_size):
    path_maze = copy.deepcopy(maze)
    findPath(maze, row_size, col_size, 0, 0, path_maze)
    print_maze(path_maze, row_size, col_size)
    return


def findPath(maze, row_size, col_size, r_idx, c_idx, path_maze):
    """
        Finds a path from cell (0,0) to cell (M-1,N-1) if a path exists
        (r_idx,c_idx) -> M index and N index of the cell
    """

    # destination cell - found a path
    if r_idx == row_size-1 and c_idx == col_size-1:
        path_maze[r_idx][c_idx] = 1
        return True

    if valid_cell(maze, row_size, col_size, r_idx, c_idx, path_maze):
        """
            cell is valid i.e we can move to the cell
        """
        path_maze[r_idx][c_idx] = 1

        """
            recursively check if a path exists from the current valid (safe) cell
            start checking from cell (r_idx+1,c_idx)
            start checking from cell (r_idx,c_idx+1)
        """
        if findPath(maze, row_size, col_size, r_idx+1, c_idx, path_maze) or\
           findPath(maze, row_size, col_size, r_idx-1, c_idx, path_maze) or\
           findPath(maze, row_size, col_size, r_idx, c_idx+1, path_maze) or\
           findPath(maze, row_size, col_size, r_idx, c_idx-1, path_maze):
            return True
        else:
            path_maze[r_idx][c_idx] = 0
            return False

    return False


def print_maze(maze, row_size, col_size):
    for i in range(row_size):
        for j in range(col_size):
            if j == col_size - 1:
                print(maze[i][j])
            else:
                print(maze[i][j], end=" ")


def main():
    row_size = 6
    col_size = 6
    maze = [[0, 1, 1, 1, 1, 1],
            [0, 1, 0, 0, 0, 0],
            [0, 1, 0, 1, 1, 0],
            [0, 1, 0, 0, 1, 0],
            [0, 1, 1, 0, 1, 0],
            [0, 0, 0, 0, 1, 0]
            ]
    any_path_in_maze(maze, row_size, col_size)

if __name__ == '__main__':
    main()

