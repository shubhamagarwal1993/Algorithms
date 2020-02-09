/*
 * Find a path from cell (0,0) to cell (M-1,N-1) if a path exists
 * Print the path matrix.
 * 1s in the maze denotes barriers (dangerous cells)
 */

#include <iostream>

using namespace std;

#define M 6
#define N 6

void printPathMatrix(int path[M][N]) {

   cout<<"\nPath in Maze :-\n";
   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         cout<<path[i][j] << " ";
      }
      cout<<endl;
   }
}

// check if we can move to a particular cell
bool safeCell(int maze[5][7], int r_idx, int c_idx) {
    // invalid M index
    if (r_idx < 0 || r_idx >= 5) return false;

    // inavlid N index
    if (c_idx < 0 || c_idx >= 7) return false;

    // cannot move to this cell
    if (maze[r_idx][c_idx] != 0) return false;

    return true;
}

// check if we can move to a particular cell
bool validCell(int maze[M][N], int r_idx, int c_idx, int path[M][N]) {
    // invalid M index      
    if (r_idx < 0 || r_idx >= M) return false;

    // inavlid N index
    if (c_idx < 0 || c_idx >= N) return false;

    // cannot move to this cell
    if (maze[r_idx][c_idx] != 0) return false;

    // have already been through this cell
    if (path[r_idx][c_idx] != 0) return false;

    return true;
}

bool findPath(int maze[M][N], int r_idx, int c_idx, int path[N][N]) {

    // base case - last cell
    if ((r_idx == M-1) && (c_idx == N-1)) {
      // we have reached the last cell
      // this implies we have found a path
      path[r_idx][c_idx] = 1;
      return true;
    }

    if (validCell(maze, r_idx, c_idx, path)) {
        // cell is valid i.e we can move to the cell
        path[r_idx][c_idx] = 1;

        // recursively check if a path exists from the current valid (safe) cell
        // start checking from cell (r_idx+1,c_idx)
        // start checking from cell (r_idx,c_idx+1)
        if( (findPath(maze,r_idx+1,c_idx,path)) 
         || (findPath(maze,r_idx-1,c_idx,path))
         || (findPath(maze,r_idx,c_idx+1,path))
         || (findPath(maze,r_idx,c_idx-1,path))) {
            return true;
        } else {
            path[r_idx][c_idx] = 0;
            return false;
        }
    }

    return false;
}

void pathInMaze(int maze[M][N]) {
   int path[M][N];

   // initialize path matrix
   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         path[i][j] = 0;
      }
   }

   // find the path if available
   if (findPath(maze, 0, 0, path)) {
      cout << "Path exists:" << endl;
      printPathMatrix(path);
   } else {
      cout<<"\nPath doesn't exist ...\n";
   }
}

void findTotalPaths(int maze[5][7]) {
    int row = 5;
    int col = 7;

    // initialize cells in first column to 1 that are accessible from (0, 0)
    for(int i = 0; i < row; i++) {
        if(maze[i][0] == 0) {
            maze[i][0] = 1;
        } else {
            break;
        }
    }

    // initialize cells in first row to 1 that are accessible from (0, 0)
    for(int i = 1; i < col; i++) {
        if(maze[0][i] == 0) {
            maze[0][i] = 1;
        } else {
            break;
        }
    }

    // for each accessible cell, increase total count of paths
    for(int i = 1; i < col; i++) {
        for(int j = 1; j < row; j++) {
            if(maze[j][i] == -1) {
                continue;
            }

            if(maze[j][i-1] > 0) {
                maze[j][i] = maze[j][i] + maze[j][i-1];
            }

            if(maze[j-1][i] > 0) {
                maze[j][i] = maze[j][i] + maze[j-1][i];
            }
        }
    }

    cout << "---------" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(maze[i][j] == -1) {
                cout << maze[i][j] << " ";
            } else {
                cout << " " << maze[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "---------" << endl;

    cout << "Total paths in maze with barriers: " << maze[row-1][col-1] << endl;
}

void printAllPathsUtil(int maze[5][7], int row, int col, int path[11], int path_index) {

    if((row == 4) && (col == 6)) {
        path[path_index] = maze[row][col];
        for(int i = 0; i < 11; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    if(safeCell(maze, row, col)) {

        path[path_index] = maze[row][col];

        printAllPathsUtil(maze, row, col+1, path, path_index+1);
        printAllPathsUtil(maze, row+1, col, path, path_index+1);

        path[path_index] = 0;
    }

    return;
}

void printAllPaths(int maze[5][7]) {

    int ROW = 5;
    int COL = 7;
    int path[ROW + COL - 1];
    for(int i = 0; i < ROW + COL - 1; i++) {
        path[i] = 0;
    }

    printAllPathsUtil(maze, 0, 0, path, 0);
}

int main() {
   int maze[M][N] = {{ 0,1,1,1,1,1 },
                     { 0,1,0,0,0,0 },
                     { 0,1,0,1,1,0 },
                     { 0,1,0,0,1,0 },
                     { 0,1,1,0,1,0 },
                     { 0,0,0,0,1,0 }};

   pathInMaze(maze);
   cout << endl;

   int maze_with_barriers[5][7] = {{ 0,  0,  0, 0,  0, -1,  0},
                                   { 0, -1,  0, 0,  0,  0, -1},
                                   {-1,  0,  0, 0, -1,  0,  0},
                                   { 0,  0, -1, 0,  0,  0,  0},
                                   { 0,  0,  0, 0, -1,  0,  0}};
   findTotalPaths(maze_with_barriers);

    //    printAllPaths(maze_with_barriers);

   return 0;
}

