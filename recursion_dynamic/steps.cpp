/*
 * Given array of steps, find total possible ways
 */
#include <iostream>
#include <vector>

using namespace std;

int permutation_steps(int arr[], int arr_size) {
    vector<int> memo;
    for(int i = 0; i < arr_size; i++) {
        memo.push_back(0);
    }

    // first element
    int index = 0;
    memo[index] = arr[index];

    // all others will be a combination of pervious steps
    for(int i = 1; i < arr_size; i++) {
        // only allowed cells
        if(arr[i] == 0) {
            continue;
        }

        // for 1 step back
        if(i - 1 >= 0) {
            memo[i] = memo[i-1];
        }

        // for 2 steps back
        if(i - 2 >= 0) {
            memo[i] += memo[i-2];
        }

        // for 3 steps back
        if(i - 3 >= 0) {
            memo[i] += memo[i-3];
        }
    }

    return memo[arr_size - 1];
}

int steps_recursive_util(int arr[], int arr_size, vector<int> path) {
    int steps = 0;
    if(arr_size < 0) {
        return 0;
    }

    if(arr_size == 0) {
        if(path.front() == 4) {
            for(int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << endl;
            return 1;
        }
    }

    if(arr[arr_size - 3] == 1) {
        path.push_back(arr_size - 3);
        steps += steps_recursive_util(arr, arr_size - 3, path);
        path.pop_back();
    }

    if(arr[arr_size - 2] == 1) {
        path.push_back(arr_size - 2);
        steps += steps_recursive_util(arr, arr_size - 2, path);
        path.pop_back();
    }

    if(arr[arr_size - 1] == 1) {
        path.push_back(arr_size - 1);
        steps += steps_recursive_util(arr, arr_size - 1, path);
        path.pop_back();
    }

    return steps;
}

int steps_recursive(int arr[], int arr_size) {
    vector<int> path;

    return steps_recursive_util(arr, arr_size, path);
}

int shortest_steps_util(int arr[], int arr_size, vector<int> path) {
    int steps = 0;
    if(arr_size < 0) {
        return 0;
    }

    if(arr_size == 0) {
        if(path.front() == 4) {
            for(int i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << endl;
            return 1;
        }
    }

    if(arr[arr_size - 3] == 1) {
        path.push_back(arr_size - 3);
        steps += steps_recursive_util(arr, arr_size - 3, path);
        path.pop_back();
    }

    if(arr[arr_size - 2] == 1) {
        path.push_back(arr_size - 2);
        steps += steps_recursive_util(arr, arr_size - 2, path);
        path.pop_back();
    }

    if(arr[arr_size - 1] == 1) {
        path.push_back(arr_size - 1);
        steps += steps_recursive_util(arr, arr_size - 1, path);
        path.pop_back();
    }

    return steps;
}

void shortest_steps(int arr[], int arr_size) {
    vector<int> path;

    cout << shortest_steps_util(arr, arr_size, path) << endl;
    return;
}

int main() {
    int arr[] = {1, 1, 0, 1, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    // Total combinations
    // Time: O(n) where n is total steps
    // Space: O(n) where n is total steps
    // Pros: fast
    // Cons: cannot find what are the different steps
    cout << "Total combinations: " << permutation_steps(arr, arr_size) << endl;

    // Total combinations with steps
    // Time: Exponential
    // Space: O(n) space used on stack
    int steps_count = steps_recursive(arr, arr_size);
    cout << "Total steps rercursively: " << steps_count << endl;

    shortest_steps(arr, arr_size);

    return 0;
}
