#include <iostream>

#define M 6
#define N 6
using namespace std;

/* print the path matrix
  '1' is present in the cell which is a part of the path
*/
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

/* finds a path from cell (0,0) to cell (M-1,N-1) if a path exists
   (r_idx,c_idx) -> M index and N index of the cell
*/
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

// wrapper function
void pathInMaze(int maze[M][N]) {
   int path[N][N];

   // initialize path matrix
   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         path[i][j] = 0;
      }
   }

   // find the path if available
   if (findPath(maze, 0, 0, path)) {
      cout<<"\nPath exists ...\n";
      printPathMatrix(path);
   } else {
      cout<<"\nPath doesn't exist ...\n";
   }
}

// main
int main() {
   int maze[M][N] = {{ 0,1,1,1,1,1 },
                     { 0,1,0,0,0,0 },
                     { 0,1,0,1,1,0 },
                     { 0,1,0,0,1,0 },
                     { 0,1,1,0,1,0 },
                     { 0,0,0,0,1,0 }};
   // 1s in the maze denotes barriers (dangerous cells),
   pathInMaze(maze);
   cout<<endl;
   return 0;
}

