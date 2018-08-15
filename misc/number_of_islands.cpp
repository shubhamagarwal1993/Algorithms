// Given a boolean 2D matrix, find the number of islands
// A group of connected 1s forms an island

#include <iostream>

using namespace std;

#define COL 5
#define ROW 5

bool isSafe(int M[ROW][COL], int row, int col, bool visited[][COL]) {
    if(row < 0 || row >= ROW) {
        return false;
    }

    if(col < 0 || col >= COL) {
        return false;
    }

    if(visited[row][col]) {
        return false;
    }

    if(!M[row][col]) {
        return false;
    }

    return true;
}

void DFS(int M[ROW][COL], int row, int col, bool visited[ROW][COL]) {

    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; k++) {
        if(isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) {
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
        }
    }
}

int countIslands(int M[ROW][COL]) {

    // Make a bool array to mark visited cells, cells unvisited initially
    bool visited[ROW][COL];
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }

    int island_count = 0;

    // visit all elements in 2D matrix
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            // If cell has value 1 and is not visited, then new island found
            if (M[i][j] && !visited[i][j]) {
                // Take this element and find all connected 1s
                // This will make all elements of current island visited
                DFS(M, i, j, visited);
                island_count += 1;
            }
        }
    }

    return island_count;
}

int main() {
    int M[ROW][COL] = {{1, 1, 0, 0, 0},
                       {0, 1, 0, 0, 1},
                       {1, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0},
                       {1, 0, 1, 0, 1}
                      };

    cout << "Number of islands are: " << countIslands(M) << endl;
    return 0;
}

