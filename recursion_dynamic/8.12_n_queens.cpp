#include <iostream>

#define N 8
using namespace std;

bool isSafe(int chessboard[N][N], int row, int col) {
    // check all rows above current row
    for(int j = 0; j < row; j++) {

        // check for same column
        if(chessboard[j][col]) {
            return false;
        }

        // check for 45 deg and 135 deg diagonal
        for(int i = 0; i < N; i++) {
            if((j - row == i - col) && (chessboard[j][i])) {
                return false;
            }

            if((j - row == col - i) && (chessboard[j][i])) {
                return false;
            }
        }
    }
    return true;
}

bool nQueens(int chessboard[N][N], int row) {
    // base case
    if(row >= N) {
        return true;
    }

    // check for each column on the chessboard where new queen can be placed
    for(int col = 0; col < N; col++) {

        if(isSafe(chessboard, row, col)) {
            // place queen on new position
            chessboard[row][col] = 1;

            // find next queen's position
            if(nQueens(chessboard, row+1)) {
                return true;
            }

            // if no available position in row, backtrack
            chessboard[row][col] = 0;
        }
    }

    return false;
}


int main() {

    // make chessboard and initialize it
    int chessboard[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            chessboard[i][j] = 0;
        }
    }

    if(nQueens(chessboard, 0)) {
        // print chessboard
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << chessboard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "No possible solutions" << endl;
    }

    return 0;
}

