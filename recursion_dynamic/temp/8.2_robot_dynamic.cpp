#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define M 4
#define N 4

using namespace std;

int path_flag = 0;

void printPathMatrix(int path[M][N]) {
    int i,j;
    cout<<"\nPath in Maze :-\n";
    
    for(i=0;i<M;i++) {
        for(j=0;j<N;j++) {
            cout << path[i][j] << "\t";
        }
        cout<<endl;
    }
}

bool validCell(int maze[M][N], int start_row, int start_col) {
    if(start_row < 0 || start_row >= M)
        return false;
 
    if(start_col < 0 || start_col >= N)
        return false;
 
    if(maze[start_row][start_col] != 0)
        return false;
 
    return true;
}

bool findPath(int maze[M][N], int start_row, int start_col, int destination_row, int destination_col, int path[N][N], int &count) {
    //if we reach the last cell and column -> that is also the destination, then return true
    if((start_row == destination_row) && (start_col == destination_col)) {
        count = count + 1;
        path_flag = 1;
        path[start_row][start_col] = 12;
        printPathMatrix(path);
//        return true;
    }

    if(validCell(maze, start_row, start_col)) {
        // cell is valid i.e we can move to the cell
        if (path[start_row][start_col] != 12)
            path[start_row][start_col] = 12;
        else
            return false;
        // recursively check if a path exists from the current valid (safe) cell

        // down
        if(findPath(maze, start_row+1, start_col, destination_row, destination_col, path, count))
            return true;

        // right
        if(findPath(maze, start_row, start_col+1, destination_row, destination_col, path, count))
            return true;

        // up
        if(findPath(maze, start_row-1, start_col, destination_row, destination_col, path, count))
            return true;

        // left
        if(findPath(maze, start_row, start_col-1, destination_row, destination_col, path, count))
            return true;

        path[start_row][start_col] = 0;
        return false;

        findPath(maze, start_row+1, start_col, destination_row, destination_col, path, count);
        findPath(maze, start_row-1, start_col, destination_row, destination_col, path, count);
        findPath(maze, start_row, start_col+1, destination_row, destination_col, path, count);
        findPath(maze, start_row, start_col-1, destination_row, destination_col, path, count);
    }
    return false;
}

void pathInMaze(int maze[M][N], int start_row, int start_col, int destination_row, int destination_col) {
    int path[N][N];
 
    // initialize path matrix
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            path[i][j] = 0;
 
    //no of possible paths
    int count = 0;
 
    // find the path
    findPath(maze, start_row, start_col, destination_row, destination_col, path, count);

    //check if path exists or not
    if (path_flag == 1) {
        cout << "\nPath exists ...\n";
        cout << count << " possible paths" << endl;
    } else {
        cout << "\nPath doesn't exist ...\n";
        cout << count << " possible paths" << endl;
    }
}

int main() {

    //make a maze
    int maze[M][N] = { {0,0,1,0},
                       {0,0,0,0},
                       {0,1,0,1},
                       {0,0,0,0} };

    // 0 means safe cell and we can still go on it
    // 1 means unsafe cell and we cannot go on it
    //12 means safe cell and visited cell

    int start_row = 2;
    int start_col = 2;
    int destination_row = 2;
    int destination_col = 0;

    if (!validCell(maze, start_row, start_col)) {
        cout << "\nStart cell not valid ...\n\n";
        return 0;
    }

    if(!validCell(maze, destination_row, destination_col)) {
        cout << "\nDestination cell not valid ...\n\n";
        return 0;
    }
 
    //find path in maze -> can travel in all directions
    pathInMaze(maze, start_row, start_col, destination_row, destination_col);
    cout << endl;
    return 0;
}

