#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxSubArraySum(int arr[], int arr_size) {
	// will maintain max value at any point of time
	int max_so_far = 0;
    int max_so_far_index = 0;
    int max_length_so_far = 0;

    int max_index_final = 0;
    int max_length_final = 0;
	// will check sum on each iteration
	int max_ending_here = 0;

	for(int i = 0; i < arr_size; i++) {
		// add current value to check if will be kept or removed
		max_ending_here = max_ending_here + arr[i];
        max_length_so_far++;

		// update max value
		if(max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
            max_length_final = max_length_so_far;
            max_index_final = max_so_far_index;
		}

		// if less than 0, then dont add
		if(max_ending_here < 0) {
			max_ending_here = 0;
            max_so_far_index = i + 1;
            max_length_so_far = 0;
		}
	}

    cout << max_index_final << endl;
    cout << max_length_so_far << endl;
	return max_so_far;
}

int main() {
	int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int max_sum = maxSubArraySum(arr, arr_size);
	cout << "Maximum contiguous sum is: " << max_sum << endl;
	return 0;
}

// Initialize:
//     max_so_far = 0
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_ending_here < 0)
//             max_ending_here = 0
//   (c) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
// return max_so_far
