#include <iostream>

#define M 3
#define N 3
using namespace std;

void minPathInMaze(int maze[M][N]) {
    int row = N;
    int col = M;

    int testMaze[M][N];

    testMaze[0][0] = maze[0][0];

    // initialize cells in first column to total cost to reach it from (0, 0)
    for(int i = 1; i < row; i++) {
        testMaze[i][0] = maze[i][0] + testMaze[i-1][0];
    }

    // initialize cells in first row to total cost to reach it from (0, 0)
    for(int i = 1; i < col; i++) {
        testMaze[0][i] = maze[0][i] + testMaze[0][i-1];
    }

    // for each accessible cell, increase total count of paths
    for(int i = 1; i < col; i++) {
        for(int j = 1; j < row; j++) {
            testMaze[j][i] = maze[j][i] + min(min(testMaze[j][i-1], testMaze[j-1][i]), testMaze[j-1][i-1]);
        }
    }

    cout << "---------" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << " " << testMaze[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------" << endl;

    cout << "Min cost to reach end of maze: " << testMaze[M-1][N-1] << endl;
}

// main
int main() {
   int maze[M][N] = {{ 1,2,3 },
                     { 4,8,2 },
                     { 1,5,3 }};
   minPathInMaze(maze);
   return 0;
}

