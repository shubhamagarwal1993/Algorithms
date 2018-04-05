// Knight's tour is a chess problem such that we have to find a path for a knight
// that starts at 0,0 to visit each square on the board once

// The top left square is 0, as it is the first position / move of the knight

#include <iostream>
#include <list>
#include <stack>
#include <vector>

#define N 8

using namespace std;

bool safeCell(int x, int y, int chessboard[N][N]) {
    return ((x >= 0) && (x < N) && (y >= 0) && (y < N) && (chessboard[x][y] == -1));
}

bool knights_path(int chessboard[N][N], int x, int y, int xMove[], int yMove[], int total_moves) {

    // base case
    if(total_moves == N * N) {
        return true;
    }

    for(int k = 0; k < N; k++) {
        int x_next = x + xMove[k];
        int y_next = y + yMove[k];
        if(safeCell(x_next, y_next, chessboard)) {
            chessboard[x_next][y_next] = total_moves;
            // now check for other cells or backtrack
            if(knights_path(chessboard, x_next, y_next, xMove, yMove, total_moves+1)) {
                return true;
            } else {
                chessboard[x_next][y_next] = -1;
            }
        }
    }

    return false;
}

int main() {

    // Create chessboard
    int chessboard[N][N];

    // possible x and y moves for a knight
   int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // initialize chessboard
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            chessboard[i][j] = -1;
        }
    }

    // initial position of knight
    chessboard[0][0] = 0;

    // Solve for knight's path
    if(knights_path(chessboard, 0, 0, xMove, yMove, 1)) {
        // print chessboard
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << chessboard[i][j] << " ";
            }
            cout << endl;
        }
    cout << endl;
    } else {
        cout << "No path found" << endl;
    }


    return 0;
}

