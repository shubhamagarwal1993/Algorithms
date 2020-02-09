#include <iostream>

using namespace std;

// check if we can move to a particular cell
bool validCell(int maze[6][6], int r_idx, int c_idx, int path[6][6]) {
    // invalid M index
    if(r_idx < 0 || r_idx >= 6) {
        return false;
    }

    // inavlid N index
    if(c_idx < 0 || c_idx >= 6) {
        return false;
    }

    // cannot move to this cell
    if(maze[r_idx][c_idx] != 0) {
        return false;
    }

    // have already been through this cell
    if(path[r_idx][c_idx] != 0) {
        return false;
    }

    return true;
}

/**
 * finds a path from cell (0,0) to cell (M-1,N-1) if a path exists
 * (r_idx,c_idx) -> M index and N index of the cell
 */
bool findPath(int maze[6][6], int r_idx, int c_idx, int path[6][6]) {

    // base case - last cell
    if((r_idx == 6-1) && (c_idx == 6-1)) {
        // we have reached the last cell
        // this implies we have found a path
        path[r_idx][c_idx] = 1;
        return true;
    }

    if(validCell(maze, r_idx, c_idx, path)) {
        // cell is valid i.e we can move to the cell
        path[r_idx][c_idx] = 1;

        // recursively check if a path exists from the current valid (safe) cell
        // start checking from cell (r_idx+1,c_idx)
        // start checking from cell (r_idx,c_idx+1)
        if( (findPath(maze,r_idx+1,c_idx,path)) 
         || (findPath(maze,r_idx-1,c_idx,path))
         || (findPath(maze,r_idx,c_idx+1,path))
         || (findPath(maze,r_idx,c_idx-1,path))) {
            return true;
        } else {
            path[r_idx][c_idx] = 0;
            return false;
        }
    }

    return false;
}

void pathInMaze() {

    // 1s in the maze denotes barriers (dangerous cells),
    int ROW = 6;
    int COL = 6;
    int maze[6][6] = {{ 0,1,1,1,1,1 },
                      { 0,1,0,0,0,0 },
                      { 0,1,0,1,1,0 },
                      { 0,1,0,0,1,0 },
                      { 0,1,1,0,1,0 },
                      { 0,0,0,0,1,0 }};

    int path[6][6];

    // initialize path matrix
    for(int i = 0; i < ROW; i++) {
       for(int j = 0; j < COL; j++) {
           path[i][j] = 0;
       }
    }

    // find the path if available
    if(findPath(maze, 0, 0, path)) {
        cout << "Path exists" << endl;
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                cout<<path[i][j] << " ";
            }
            cout<<endl;
        }
    } else {
        cout << "Path doesn't exist" << endl;
    }
}

int main() {
    // checks if path exists in maze
    pathInMaze();

    return 0;
}

