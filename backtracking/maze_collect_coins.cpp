#include <iostream>

#define M 5
#define N 5
using namespace std;

// check if we can move to a particular cell
bool validCell(int r_idx, int c_idx) {
    // invalid M index      
    if (r_idx < 0 || r_idx >= M) return false;

    // inavlid N index
    if (c_idx < 0 || c_idx >= N) return false;

    return true;
}

int collectMaxCoinsRecursive(char maze[M][N], int row, int col, int dir) {

    if(!validCell(row, col) || maze[row][col] == '#') {
        return 0;
    }

    int result = maze[row][col] == 'C' ? 1 : 0;

    // If direction is right, we can only move right or down
    // If direction is left, we can only more left or down
    if(dir == 1) {
        return result + max(collectMaxCoinsRecursive(maze, row, col+1, 1), collectMaxCoinsRecursive(maze, row+1, col, 0));
    } else {
        return result + max(collectMaxCoinsRecursive(maze, row, col-1, 0), collectMaxCoinsRecursive(maze, row+1, col, 1));
    }
}

int collectMaxCoinsDpUtil(char maze[M][N], int row, int col, int dir, int dp[M][N][2]) {

    // invalid cell
    if(!validCell(row, col) || maze[row][col] == '#') {
        return 0;
    }

    // value already computed
    if(dp[row][col][dir] != -1) {
        return dp[row][col][dir];
    }

    dp[row][col][dir] = maze[row][col] == 'C' ? 1 : 0;

    if(dir == 1) {
        dp[row][col][dir] += max(collectMaxCoinsDpUtil(maze, row, col+1, 1, dp), collectMaxCoinsDpUtil(maze, row+1, col, 0, dp));
    }

    if(dir == 0) {
        dp[row][col][dir] += max(collectMaxCoinsDpUtil(maze, row, col-1, 0, dp), collectMaxCoinsDpUtil(maze, row+1, col, 1, dp));
    }

    return dp[row][col][dir];
}

void collectMaxCoinsDp(char maze[M][N]) {
    int dp[M][N][2];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << "Total coins: " << collectMaxCoinsDpUtil(maze, 0, 0, 1, dp) << endl;
    return;
}

int main() {
    char maze[M][N] = {{'E','C','C','C','C'},
                       {'C','#','C','#','E'},
                       {'#','C','C','#','C'},
                       {'C','E','E','C','E'},
                       {'C','E','#','C','E'}};

    // Recursive soln - exponential time
    cout << "total coins: " << collectMaxCoinsRecursive(maze, 0, 0, 1) << endl;

    // Recursuve soln - with memoization
    // Time complexity - O(row x col x d) - since d is 2, we have O(row x col)
    collectMaxCoinsDp(maze);

    return 0;
}
