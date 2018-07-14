#include <iostream>

#define M 3
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

bool printMinCostPath(int testMaze[M][N], int r, int c) {
    if((r == 0) && (c == 0)) {
        cout << r << "-" << c << endl;
        return true;
    }

    if (validCell(r, c)) {

        cout << r << "-" << c << endl;

        int min_r = -1;
        int min_c = -1;
        int min_cost = INT_MAX;

        // find min in neighbors
        if(validCell(r-1, c) && (testMaze[r-1][c] < min_cost)) {
            min_cost = testMaze[r-1][c];
            min_r = r-1;
            min_c = c;
        }

        if(validCell(r, c-1) && (testMaze[r][c-1] < min_cost)) {
            min_cost = testMaze[r][c-1];
            min_r = r;
            min_c = c-1;
        }

        if(validCell(r-1, c-1) && (testMaze[r-1][c-1] < min_cost)) {
            min_cost = testMaze[r-1][c-1];
            min_r = r-1;
            min_c = c-1;
        }

        // recursive call on smallest cost path
        if(printMinCostPath(testMaze, min_r, min_c)) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

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

    // print path coordinates
    printMinCostPath(testMaze, M-1, N-1);
}

// main
int main() {
   int maze[M][N] = {{ 1,2,3 },
                     { 4,8,2 },
                     { 1,5,3 }};
   minPathInMaze(maze);
   return 0;
}

