/*
 * The knapsack problem or rucksack problem is a problem in combinatorial optimization
 *
 * Given a set of items, each with a weight and a value, determine the number of each item to include in a collection
 * so that the total weight is less than or equal to a given limit and the total value is as large as possible
 */
#include <iostream>
#include <vector>

using namespace std;

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
    return 0;
}
