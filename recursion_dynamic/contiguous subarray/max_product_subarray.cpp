#include <iostream>
#include <vector>

using namespace std;

// Utility functions to get minimum of two integers
int min (int x, int y) {return x < y? x : y; }

// Utility functions to get maximum of two integers
int max (int x, int y) {return x > y? x : y; }

// Running time: O(n)
int maxSubArrayProduct(int arr[], int arr_size) {
    if(arr_size == 0) {
        return 0;
    }

    // Initialize:
    int max_so_far = 1;
    int max_ending_here = 1;
    // min negative product ending at current position
    int min_ending_here = 1;

    for(int i = 0; i < arr_size; i++) {

        // positive number
        if(arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min(min_ending_here * arr[i], 1);
        } else if(arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
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



//	const int n = a.size(); 
//	long long p = 1;
//	int res = 0;
//	for (int start = 0, end = 0; end < n; end++) {
//
//		// Move right bound by 1 step. Update the product.
//		p *= a[end];
//		
//		// Move left bound so guarantee that p is again 
//		// less than k.
//		while (start < end && p >= k) 
//			p /= a[start++];	 
//		
//		// If p is less than k, update the counter.
//		// Note that this is working even for (start == end):
//		// it means that the previous window cannot grow 
//		// anymore and a single array element is the only 
//		// addendum.
//		if (p < k) {
//			int len = end-start+1;
//			res += len;
//		}
//	}
//
//	return res;
//}
//
//// Driver Function to count number of
//// such arrays
//int main()
//{
//	cout << countSubArrayProductLessThanK({1, 2, 3, 4, 11}, 10) << endl;
//	cout << countSubArrayProductLessThanK({1, 9, 2, 51, 8, 6, 4, 3}, 100) << endl;
//	cout << countSubArrayProductLessThanK({5, 3, 2}, 16) << endl;
//	cout << countSubArrayProductLessThanK({100, 200}, 100) << endl;
//	cout << countSubArrayProductLessThanK({100, 200}, 101) << endl;
//}

