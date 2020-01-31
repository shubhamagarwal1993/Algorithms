#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

void least_resistent_path_recursive(vector<vector<int>> graph, tuple<int, int>coord_src, int row_len, int col_len, vector<tuple<int, int>> path, vector<tuple<int, int>> &shortest_path, int &shortest_path_sum) {

    // Base case
    if((std::get<0>(coord_src) == row_len - 1) && (std::get<1>(coord_src) == col_len - 1)) {
        path.push_back(coord_src);
        int sum = 0;

        for(int i = 0; i < path.size(); i++) {
            int temp_row = get<0>(path[i]);
            int temp_col = get<1>(path[i]);

            // cout << "(" << temp_row << ", " << temp_col << ")" << " ";
            sum += graph[temp_row][temp_col];
        }

        if(sum <= shortest_path_sum) {
            shortest_path = path;
            shortest_path_sum = sum;
        }
        // cout << sum << endl;

        return;
    }

    path.push_back(coord_src);
    int row_idx = std::get<0>(coord_src);
    int col_idx = std::get<1>(coord_src);
    if(row_idx + 1 < row_len) {
        tuple<int, int> curr_coord = tuple<int, int>{row_idx+1, col_idx};
        least_resistent_path_recursive(graph, curr_coord, row_len, col_len, path, shortest_path, shortest_path_sum);
    }
    if(col_idx + 1 < col_len) {
        tuple<int, int> curr_coord = tuple<int, int>{row_idx, col_idx+1};
        least_resistent_path_recursive(graph, curr_coord, row_len, col_len, path, shortest_path, shortest_path_sum);
    }

    // backtrack
    path.pop_back();
    return;
}

void least_resistent_path(vector<vector<int>> graph, tuple<int, int>coord_src, int row_len, int col_len) {

    // Path weigth storage graph
    vector<vector<int>> weight = {{0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};

    weight[0][0] = graph[0][0];

    // copy the first row over since there is only one way
    for(int i = 1; i < col_len; i++) {
        weight[0][i] = graph[0][i] + weight[0][i-1];
    }

    // copy the first col over since there is only one way
    for(int i = 1; i < row_len; i++) {
        weight[i][0] = graph[i][0] + weight[i-1][0];
    }

    // fill the rest with min of up or left nodes
    for(int row_idx = 1; row_idx < row_len; row_idx++) {
        for(int col_idx = 1; col_idx < col_len; col_idx++) {
            weight[row_idx][col_idx] = graph[row_idx][col_idx] + min(weight[row_idx-1][col_idx], weight[row_idx][col_idx-1]);
        }
    }

    // print cost map
    for(int row_idx = 0; row_idx < row_len; row_idx++) {
        for(int col_idx = 0; col_idx < col_len; col_idx++) {
            cout << weight[row_idx][col_idx] << " ";
        }
        cout << endl;
    }

    // find least resistent pathh
    int row_idx = row_len - 1;
    int col_idx = col_len - 1;
    while((row_idx >= 0) && (col_idx >= 0)) {
        cout << "(" << row_idx << ", " << col_idx << ")";

        int left_val = INT_MAX;
        int top_val = INT_MAX;

        // Get bottom val, and right val
        if(row_idx - 1 >= 0) {
            top_val = weight[row_idx - 1][col_idx];
        }
        if(col_idx - 1 >= 0) {
            left_val = weight[row_idx][col_idx - 1];
        }

        cout << " => top val " << top_val << " => left val " << left_val << endl;
        if(top_val < left_val) {
            row_idx = row_idx - 1;
            col_idx = col_idx;
        } else {
            row_idx = row_idx;
            col_idx = col_idx - 1;
        }
    }

    return;
}

int main() {
    int row_len = 5;
    int col_len = 5;

    vector<vector<int>> graph = {{3, 8, 5, 3, 7},
                                 {9, 5, 2, 4, 8},
                                 {2, 6, 2, 8, 4},
                                 {1, 0, 8, 3, 5},
                                 {6, 3, 7, 2, 4}};

    std::tuple<int, int> coord_src = std::tuple<int, int>{0, 0};

    // Time: O(row*col): Graph is traversed twice
    // Space: (row*col): Weighthed graph takes as much space as given graph
    least_resistent_path(graph, coord_src, row_len, col_len);

    // Time: Exponential O: Graph is traversed twice
    // Space: (row + col - 1): Path from start to end
    graph = {{3, 8, 5, 3, 7},
             {9, 5, 2, 4, 8},
             {2, 6, 2, 8, 4},
             {1, 0, 8, 3, 5},
             {6, 3, 7, 2, 4}};
    row_len = 5;
    col_len = 5;
    vector<tuple<int, int>> path;
    vector<tuple<int, int>> shortest_path;
    int shortest_path_sum = INT_MAX;
    least_resistent_path_recursive(graph, coord_src, row_len, col_len, path, shortest_path, shortest_path_sum);
    cout << "SHORTEST PATH: ";
    for(int i = 0; i < shortest_path.size(); i++) {
        int temp_row = get<0>(shortest_path[i]);
        int temp_col = get<1>(shortest_path[i]);
        cout << "(" << temp_row << ", " << temp_col << ")" << " ";
    }
    cout << shortest_path_sum << endl;

    return 0;
}
