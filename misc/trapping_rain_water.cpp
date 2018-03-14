#include <iostream>
#include <unordered_map>

using namespace std;

int findWater_1(int arr[], int size) {
    // left[i] contains height of tallest bar to the left of i'th bar including itself
    int left[size];
 
    // Right [i] contains height of tallest bar to the right of ith bar including itself
    int right[size];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < size; i++)
       left[i] = max(left[i-1], arr[i]);
 
    // Fill right array
    right[size-1] = arr[size-1];
    for (int i = size-2; i >= 0; i--)
       right[i] = max(right[i+1], arr[i]);
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < size; i++)
       water += min(left[i],right[i]) - arr[i];
 
    return water;
}

int findWater_2(int arr[], int size) {
    // initialize output
    int result = 0;

    // maximum element on left and right
    int left_max = 0, right_max = 0;

    // indices to traverse the array
    int lo = 0, hi = size-1;

    while(lo <= hi) {

        if(arr[lo] < arr[hi]) {
            
            if(arr[lo] > left_max) // update max in left
                left_max = arr[lo];
            else // water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        } else {
            if(arr[hi] > right_max) // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;
}

int main() {

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    // With Space O(n) and Time O(n)
    cout << "Maximum water that can be accumulated is " << findWater_1(arr, size) << endl;

    // With Space O(1) and Time O(n)
    cout << "Maximum water that can be accumulated is " << findWater_2(arr, size) << endl;

    return 0;
}
