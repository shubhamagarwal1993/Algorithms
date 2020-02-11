/*
 * The knapsack problem or rucksack problem is a problem in combinatorial optimization
 *
 * Given a set of items, each with a weight and a value, determine the number of each item to include in a collection
 * so that the total weight is less than or equal to a given limit and the total value is as large as possible
 */
#include <iostream>
#include <vector>

using namespace std;

void knapsack_memoization() {
    // init
    int items_weight[] = {5, 4, 6, 3};
    int items_value[] = {10, 40, 30, 50};
    int items_size = 4;
    int weight_limit = 10;

    // logic
    int mat[weight_limit + 1];
    for(int i = 0; i < weight_limit + 1; i++) {
        mat[i] = 0;
    }

    for(int item_idx = 1; item_idx < items_size + 1; item_idx++) {
        for(int weight = weight_limit; weight >= 1; weight--) {
            // At row i and column j, we are tackling a sub-problem consisting of items 1, 2, 3 … i with a knapsack of j capacity.
            // There are 2 options at this point: we can either include item i or not.
            int without_value = mat[weight];

            int with_value = 0;
            int curr_weight = items_weight[item_idx - 1];
            if(weight >= curr_weight) {
                with_value = items_value[item_idx - 1];

                int weight_remaining = weight - curr_weight;
                with_value += mat[weight_remaining];
            }

            mat[weight] = max(without_value, with_value);
        }
    }

    cout << mat[weight_limit] << endl;
}

void knapsack_dynamic() {
    // init
    int items_weight[] = {5, 4, 6, 3};
    int items_value[] = {10, 40, 30, 50};
    int items_size = 4;
    int weight_limit = 10;

    // logic
    int mat[items_size+1][weight_limit+1];

    // row 0 has no items to pick from
    for(int col = 0; col < weight_limit + 1; col++) {
        mat[0][col] = 0;
    }

    // col 0 has no weight to allow any items
    for(int row = 0; row < items_size + 1; row++) {
        mat[row][0] = 0;
    }

    // 0 1 2 3 4 5 6 7 8 9 10 11
    // 1
    // 2
    // 3
    // 4
    // 5
    //
    // 0 0 0 0 0 0 0 0 0 0 0 0
    // 0
    // 0
    // 0
    // 0
    // 0

    for(int item_idx = 1; item_idx < items_size + 1; item_idx++) {
        for(int weight = 1; weight < weight_limit + 1; weight++) {
            // At row i and column j, we are tackling a sub-problem consisting of items 1, 2, 3 … i with a knapsack of j capacity.
            // There are 2 options at this point: we can either include item i or not.
            int without_value = mat[item_idx-1][weight];

            int with_value = 0;
            int curr_weight = items_weight[item_idx - 1];
            if(weight >= curr_weight) {
                with_value = items_value[item_idx - 1];

                int weight_remaining = weight - curr_weight;
                with_value += mat[item_idx - 1][weight_remaining];
            }

            mat[item_idx][weight] = max(without_value, with_value);
        }
    }

    cout << mat[items_size][weight_limit] << endl;
}

bool knapsack_naive_util(int items_weight[], int items_value[], int items_size, int value_curr, int &max_value, int weight_curr, int weight_limit, vector<int> items_vec, vector<int> &items_final) {

    // end of combination
    if(items_size == 0) {
        return false;
    }

    if (weight_curr > weight_limit) {
        return false;
    }

    // base case
    if(value_curr > max_value) {
        max_value = value_curr;
        items_final = items_vec;
    }

    // include value
    value_curr += items_value[items_size - 1];
    weight_curr += items_weight[items_size - 1];
    items_vec.push_back(items_size - 1);
    bool with = knapsack_naive_util(items_weight, items_value, items_size - 1, value_curr, max_value, weight_curr, weight_limit, items_vec, items_final);
    if(with) {
        items_vec.clear();
    } else {
        int items_remove_idx = items_vec.back();
        items_vec.pop_back();
        value_curr -= items_value[items_remove_idx];
        weight_curr -= items_weight[items_remove_idx];
    }

    return with || knapsack_naive_util(items_weight, items_value, items_size - 1, value_curr, max_value, weight_curr, weight_limit, items_vec, items_final);
}

void knapsack_naive() {
    int items_weight[] = {5, 4, 6, 3};
    int items_value[] = {10, 40, 30, 50};
    int value_curr = 0;
    int max_value = 0;

    int weight_curr = 0;
    int weight_limit = 10;

    int items_size = 4;
    vector<int> items_vec;
    vector<int> items_final;
    knapsack_naive_util(items_weight, items_value, items_size, value_curr, max_value, weight_curr, weight_limit, items_vec, items_final);
    cout << max_value << endl;
    for(int i = 0; i < items_final.size(); i++) {
        cout << items_final[i] << " ";
    }
    cout << endl;
}

int main() {
    // Exponential soln. Looks for all possible combinations and picks one with greatest value
    knapsack_naive();

    // N: size of items
    // M: weight limit
    // Space complexity: O(N*M)
    // Time complexity: O(N*M) since 2d array is filled once.
    knapsack_dynamic();

    // N: size of items
    // M: weight limit
    // Space complexity: O(M). N is no longer required since we can maintain 2 rows and get the results.
    // Time complexity: O(N*M) since all rows and col are visited once, or twice max when looking for max value in a later computation.
    knapsack_memoization();
    return 0;
}
