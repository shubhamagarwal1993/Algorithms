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

bool test(int matrix[M][N], int row_u, int row_d, int col_l, int col_r, int num, int& iter) {

    if((row_d < row_u) || (col_r < col_l)) {
        return false;
    }

    //if(iter > 10) {
    //    return false;
    //} else {
    //    iter = iter + 1;
    //}
    int row_mid = (row_d + row_u)/2;
    int col_mid = (col_r + col_l)/2;
    int mid_value = matrix[row_mid][col_mid];

    cout << row_u << " " << row_d << " " << col_l << " " << col_r << " " << mid_value << endl;
    if(mid_value == num) {
        return true;
    } else if(mid_value > num) {
        // num is in left half or top half
        return test(matrix, row_u, row_d, col_l, col_mid - 1, num, iter)
            || test(matrix, row_u, row_mid-1, col_l, col_r, num, iter);
    } else if(mid_value < num) {
//        cout << "inside greater case" << endl;
        // num is in right half or bottom half
        return test(matrix, row_u, row_d, col_mid+1, col_r, num, iter)
            || test(matrix, row_mid + 1, row_d, col_l, col_r, num, iter);
    } else {
        return false;
    }
}

int main() {

    int matrix[M][N] = {{10, 20, 30, 40, 50, 60}
                       ,{15, 25, 35, 45, 55, 65}
                       ,{27, 29, 37, 48, 57, 68}
                       ,{32, 33, 39, 50, 59, 69}
                       };

//    for(int row = 0; row < M; row++) {
//        for(int col = 0; col < N; col++) {
//            cout << matrix[row][col] << " ";
//        }
//        cout << endl;
//    }
//
//    // find element in matrix
    int element = 37;
//    if(findElementInMatrix(matrix, element)) {
//        cout << "Found element " << element << " in matrix" << endl;
//    } else {
//        cout << "Element not found" << endl;
//    }

    int row_u = 0;
    int row_d = M - 1;
    int col_l = 0;
    int col_r = N - 1;
    int iter = 0;
    cout << test(matrix, row_u, row_d, col_l, col_r, element, iter) << endl;

    return 0;
}

