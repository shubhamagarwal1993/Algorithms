#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// PSEUDO CODE
//
// arr is column containes column index for position of queen -> row = i, column arr[i]
// row is the current row we are on
// size is the size of the board
//
void nQueens(int arr[], int row, int size) {
    // base case
    if(row == size + 1) {
        for(int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
    }

    for(int j = 0; j < size; j++) {
        int legal = true;
        // check all rows above current row
        for(int i = 0; i < row; i++) {
            if( (arr[i] = j)               // same column
             || (arr[i] = j+i-row)           // diagonal
             || (arr[i] = j-i+row)           // diagonal
            ) {
                legal = false;
            }
        }

        if(legal) {
            arr[row] = j;
            nQueens(arr, row+1, size);
        }
    }
}


int main() {

    int board_size = 8;
    int arr[board_size];
    nQueens(arr, 0, board_size);

    return 0;
}

