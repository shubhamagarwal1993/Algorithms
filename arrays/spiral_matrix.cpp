#include <iostream>

using namespace std;
#define M 4
#define N 4

void print_bottom_left(int matrix[M][N], int row_start, int column_start, int row_end, int column_end);
void print_top_right(int matrix[M][N], int row_start, int column_start, int row_end, int column_end);

void print_bottom_left(int matrix[M][N], int row_start, int column_start, int row_end, int column_end) {

    // print row in reverse order
    for(int i = column_end; i >= column_start; i--) {
        cout << matrix[row_end][i] << " ";
    }

    // print column in reverse order
    for(int i = row_end - 1; i >= row_start; i--) {
        cout << matrix[i][column_start] << " ";
    }

    // check if more rows to print
    if(row_end > row_start) {
        print_top_right(matrix, row_start, column_start+1, row_end-1, column_end);
    }
}

void print_top_right(int matrix[M][N], int row_start, int column_start, int row_end, int column_end) {

    // print row
    for(int i = column_start; i <= column_end; i++) {
        cout << matrix[row_start][i] << " ";
    }

    // print column
    for(int i = row_start + 1; i <= row_end; i++) {
        cout << matrix[i][column_end] << " ";
    }

    // check if more rows to print
    if(row_end > row_start) {
        print_bottom_left(matrix, row_start+1, column_start, row_end, column_end-1);
    }
    return;
}

int** createSpiralMatrix() {

    int** arr = 0;
    arr = new int*[N];

    for(int i = 0; i < N; i++) {
        arr[i] = new int[N];
        for(int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

int main() {
    int matrix[M][N] = { {1 , 2 , 3 , 4}
                       , {12, 13, 14, 5}
                       , {11, 16, 15, 6}
                       , {10, 9 , 8 , 7}
                       };
    print_top_right(matrix, 0, 0, M-1, N-1);
    cout << endl;

    int** arr = createSpiralMatrix();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
