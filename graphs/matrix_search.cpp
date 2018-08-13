// Given sorted matrix where number below and right will always be bigger
// Find if a particular number exist in matrix

#include <iostream>

using namespace std;
#define M 4
#define N 6

/**
 * Time complexity: O(M + N)
 *
 */
bool findElementInMatrix(int matrix[M][N], int num) {

    int row = 0;
    int col = N-1;

    while((row < M) && (col >= 0)) {
        int curr_val = matrix[row][col];
        if(curr_val == num) {
            return true;
        } else if(curr_val > num) {
            col = col - 1;
        } else if(curr_val < num) {
            row = row + 1;
        } else {
            return false;
        }
    }

    return false;
}

int main() {

    int matrix[M][N] = {{10, 20, 30, 40, 50, 60}
                       ,{15, 25, 35, 45, 55, 65}
                       ,{27, 29, 37, 48, 57, 68}
                       ,{32, 33, 39, 50, 59, 69}
                       };

    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    // find element in matrix
    int element = 57;
    if(findElementInMatrix(matrix, element)) {
        cout << "Found element " << element << " in matrix" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
