// Find location of rectangle in 2D array and its dimensions

#include <iostream>

using namespace std;
#define ROW 7
#define COL 5

void find_rectangle(int matrix[ROW][COL]) {

    int sum_matrix[ROW][COL];

    // copy row from original matrix
    for(int row = 0; row < ROW; row++) {
        sum_matrix[row][0] = matrix[row][0];
    }

    // copy col from original matrix
    for(int col = 0; col < COL; col++) {
        sum_matrix[0][col] = matrix[0][col];
    }

    // loop over remaining rows and col
    for(int row = 1; row < ROW; row++) {
        for(int col = 1; col < COL; col++) {
            if(matrix[row][col] == 0) {
                sum_matrix[row][col] = 0;
            } else {
                sum_matrix[row][col] = min(sum_matrix[row-1][col], min(sum_matrix[row][col-1], sum_matrix[row-1][col-1])) + 1;
            }
        }
    }

    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COL; col++) {
            cout << sum_matrix[row][col] << " ";
        }
        cout << endl;
    }

    // find max number in 2d array and its coordinates
    int max_row_index = -1;
    int max_col_index = -1;
    int max_sum = 0;

    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COL; col++) {
            if(sum_matrix[row][col] >= max_sum) {
                max_sum = sum_matrix[row][col];
                max_row_index = row;
                max_col_index = col;
            }
        }
    }

    // print out largest rectangle
    cout << "top left corner: row = " << max_row_index - max_sum + 1 << ", col = " << max_col_index - max_sum + 1 << endl;
    cout << "bottom right corner: row = " << max_row_index << ", col = " << max_col_index << endl;
    cout << "width = " << max_sum << endl;
    cout << "height = " << max_sum - 1 << endl;

    return;
}

int main() {
    int matrix[ROW][COL] = { {0, 0, 0, 0, 0},
                             {0, 1, 1, 1, 0},
                             {0, 1, 1, 1, 0}, 
                             {0, 1, 1, 1, 0},
                             {0, 1, 1, 1, 0},
                             {0, 1, 1, 1, 0},
                             {1, 1, 1, 1, 0}
                           };
    find_rectangle(matrix);
    cout << endl;
    return 0;
}


