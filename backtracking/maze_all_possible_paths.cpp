#include <iostream>

#define M 2
#define N 3
using namespace std;

// check if we can move to a particular cell
bool validCell(int r_idx, int c_idx) {
    // invalid M index
    if (r_idx < 0 || r_idx >= M) return false;

    // inavlid N index
    if (c_idx < 0 || c_idx >= N) return false;

    return true;
}

/* finds a path from cell (0,0) to cell (M-1,N-1) if a path exists
   (r_idx,c_idx) -> M index and N index of the cell
*/
void findAllPaths(int maze[M][N], int r_idx, int c_idx, int path[M+N-1], int path_index) {

    // base case - last cell
    if ((r_idx == M-1) && (c_idx == N-1)) {
        // we have reached the last cell - print path
        path[path_index] = maze[r_idx][c_idx];
        for(int i = 0; i < M + N - 1; i++) {
             cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    if (validCell(r_idx, c_idx)) {
        // cell is valid i.e we can move to the cell
        path[path_index] = maze[r_idx][c_idx];

        // recursively check if a path exists from the current valid (safe) cell
        // start checking from cell (r_idx+1,c_idx)
        // start checking from cell (r_idx,c_idx+1)
        findAllPaths(maze, r_idx, c_idx+1, path, path_index+1);
        findAllPaths(maze, r_idx+1, c_idx, path, path_index+1);

        path[path_index] = 0;
    }

    return;
}

// wrapper function
void allPathsInMaze(int maze[M][N]) {

    int path[M + N - 1];
    for (int i = 0; i < M+N-1; i++) {
        path[i] = 0;
    }

    // find all paths
    findAllPaths(maze, 0, 0, path, 0);
}

int totalPaths(int row, int col) {
    if((row == 1) || (col == 1)) {
        return 1;
    }

    int count_rows = totalPaths(row-1, col);
    int count_cols = totalPaths(row, col-1);
    return count_rows + count_cols;
}

// main
int main() {
   int maze[M][N] = {{ 1,2,3 },
                     { 4,5,6 }};

   allPathsInMaze(maze);
   cout<<endl;

   cout << "Total paths: " << totalPaths(M, N) << endl;

   return 0;
}

