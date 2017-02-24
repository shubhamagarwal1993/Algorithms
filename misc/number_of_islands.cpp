// Given a boolean 2D matrix, find the number of islands
// A group of connected 1s forms an island

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// function does DFS on given 1 to cover all elements in that island
// Do a DFS on all 8 neighbours, as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL]) {

	// These arrays are used to get row and column numbers of 8 neighbours of a given cell
	static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
	static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};

	// Mark this cell as visited
	visited[row][col] = true;

	// Recur for all connected neighbours
	for (int k = 0; k < 8; ++k) {
		if(isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) {
			DFS(M, row + rowNbr[k], col + colNbr[k], visited);
		}
	}
}

// returns count of islands in a given boolean 2D matrix
int countIslands(int M[][COL]) {

	// Make a bool array to mark visited cells, cells unvisited initially
	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));

	int island_count = 0;

	// visit all elements in 2D matrix
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			// if cell has value 1 and is not visited, then new island found
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
	int M[][COL] = {
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1}
	};

	cout << "Number of islands are: " << countIslands(M) << endl;
    return 0;
}