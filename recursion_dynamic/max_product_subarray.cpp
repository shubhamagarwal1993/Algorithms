#include <iostream>
#include <vector>

using namespace std;

// Utility functions to get minimum of two integers
int min (int x, int y) {return x < y? x : y; }

// Utility functions to get maximum of two integers
int max (int x, int y) {return x > y? x : y; }

/*
 * Returns the product of max product subarray
 * Assumes that the given array always has a subarray with product more than 1
 *
 * Running time: O(n)
 */
int maxSubArrayProduct(int arr[], int arr_size) {
    if(arr_size == 0) {
        return 0;
    }

    // Initialize overall max product
    int max_so_far = 1;

    // Max positive product ending at the current position
    int max_ending_here = 1;

    // min negative product ending at current position
    int min_ending_here = 1;

    /*
     * Traverse through the array. Following values are maintained after the i'th iteration:
     *   max_ending_here is always 1 or some positive product ending with arr[i]
     *   min_ending_here is always 1 or some negative product ending with arr[i]
     */
    for(int i = 0; i < arr_size; i++) {

        /*
         * If this element is positive, update max_ending_here.
         * Update min_ending_here only if min_ending_here is negative
         */
        if(arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);

        /* If this element is 0, then the maximum product cannot end here
         *   make both max_ending_here and min_ending_here 0
         * Assumption: Output is alway greater than or equal to 1
         */
        } else if(arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;

        /*
         * If element is negative. This is tricky
         *   max_ending_here can either be 1 or positive
         *   min_ending_here can either be 1 or negative
         *   next min_ending_here will always be prev
         *   max_ending_here * arr[i] next max_ending_here will be 1 if prev min_ending_here is 1,
         *   otherwise next max_ending_here will be prev min_ending_here * arr[i]
         */
        } else {
            int orig_max_ending_here = max_ending_here;
            // max ending can be positive or 1
            max_ending_here = max(1, min_ending_here * arr[i]);
            min_ending_here = orig_max_ending_here * arr[i];
        }

        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }

    return max_so_far;
}

int countSubArrayProductLessThanK(vector<int> vec, int vec_size, int k) {

    // current product
    int prod = 1;

    // count of subarrays
    int count = 0;

    for(int start = 0, end = 0; end < vec_size; end++) {

        prod *= vec[end];

        while(start < end && prod > k) {
            prod /= vec[start];
            start++;
        }

        if(prod < k) {
            count += end-start+1;
        }
    }

    return count;
}

int main() {
	// Max product subarray
    int arr[] = {0, -2, -3, 0, -7, -8, -2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int max_product = maxSubArrayProduct(arr, arr_size);
	cout << "Maximum contiguous product is: " << max_product << endl;

    // Count subarray product less than k
    vector<int> vec{1, 2, 11, 3, 4};
    int k = 10;
	cout << "No of subarrays with product less than " << k << " is: " << countSubArrayProductLessThanK(vec, vec.size(), k) << endl;
	return 0;
}

