#include <iostream>
#include <unordered_map>

using namespace std;

void findMaxSum(int arr[], int size) {

    int max_sum = 0;
    int max_sum_till_here = 0;
    int arr_left_index = 0;
    int arr_right_index= 0;

    for(int i = 0; i < size; i++) {
        max_sum_till_here += arr[i];

        if(max_sum_till_here <= 0) {
            max_sum_till_here = 0;
            arr_left_index = i;
            arr_right_index = i;
        } else if(max_sum_till_here > max_sum) {
            max_sum = max_sum_till_here;
            arr_right_index = i;
        }

    }

    cout << "left index: " << arr_left_index << endl;
    cout << "right index: " << arr_right_index << endl;
    cout << "Maximum sum subarray = " << max_sum << endl;
    return;
}

void findMaxProduct(int arr[], int size) {

    int max_prod = 0;
    int arr_left_index = 0;
    int arr_right_index= 0;

    int max_prod_till_here = 1;
    int arr_left_index_temp = 0;
    int arr_right_index_temp = 0;

    for(int i = 0; i < size; i++) {

        if(arr[i] == 0) {
            max_prod_till_here = 1;
            arr_left_index_temp = i;
            arr_right_index_temp = i;
        } else {
            max_prod_till_here *= arr[i];
            arr_right_index_temp = i;

            if(max_prod_till_here > max_prod) {
                max_prod = max_prod_till_here;
                arr_right_index = i;
                arr_left_index = arr_left_index_temp;
            }
        }
    }

    cout << "left index: " << arr_left_index << endl;
    cout << "right index: " << arr_right_index << endl;
    cout << "Maximum product subarray = " << max_prod << endl;
    return;
}

int main() {

    // try all negatives, all positives, all 0, empty array, and mix
    int arr[] = {4, -1, -2, 0, 7, -2, -1};
    int size = sizeof(arr)/sizeof(arr[0]);

    // With Space O(1) and Time O(n)
    findMaxSum(arr, size);
    cout << endl;

    // With Space O(1) and Time O(n)
    findMaxProduct(arr, size);
    cout << endl;

    return 0;
}
