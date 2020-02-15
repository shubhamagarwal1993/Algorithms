// Check if any two intervals overlap among a given set of intervals

#include <iostream>
#include <vector>

using namespace std;

// An interval has start time and end time
class Interval {
    private:
        int start;
        int end;
    public:
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
        int getStart() {
            return this->start;
        }
        int getEnd() {
            return this->end;
        }
};

// Compare Intervals on start
bool compareInterval(Interval interval1, Interval interval2) {
    return (interval1.getStart() < interval2.getStart());
}

/**
 * Method 1: Use sorting
 * Running Time: O(N logN) -> sorting takes O(N logN) + loop over array O(N)
 */
int intervalsOverlap(Interval arr[], int arr_size) {

    // Sort intervals in increasing order of start time
    sort(arr, arr + arr_size - 1, compareInterval);

    // In sorted array, if start time is less than end of previous interval
    for(int i = 1; i < arr_size; i++) {
        if(arr[i - 1].getEnd() > arr[i].getStart()) {
            return i;
        }
    }

    return -1;
}

/**
 * Method 2: Use sorting
 * Running Time: O(max + N)
 *
 * Steps:
 *   - Find maximum element -> max
 *   - Initialize array of size max with 0
 *   - For every interval [start, end], increment value at index "start" (arr[start]++) 
 *     and decrement value at index "end + 1" (arr[end + 1]--)
 *   - Compute prefix sum of array
 *   - Every index, i of this prefix sum array will tell how many times i has occurred
 *     in all the intervals taken together.
 *     If this value is greater than 1, then it occurs in 2 or more intervals
 */
int intervalsOverlap1(Interval arr[], int arr_size) {

    int max = 0;

    // Find maximum element
    for(int i = 0; i < arr_size; i++) {
        if(max < arr[i].getEnd()) {
            max = arr[i].getEnd();
        }
    }

    // Intialize an array of size max
    vector<int> aux;
    for(int i = 0; i < max + 1; i++) {
        aux.push_back(0);
    }

    for(int i = 0; i < arr_size; i++) {

        int curr_start = arr[i].getStart();
        int curr_end = arr[i].getEnd();
        aux[curr_start]++;
        aux[curr_end + 1]--;
    }

    // Calculate prefix sum
    for(int i = 1; i <= max; i++) {

        aux[i] += aux[i - 1];

        // Overlap with other interval
        if(aux[i] > 1) {
            return true;
        }
    }

    return false;
}

int main() {

    // Example 1
    Interval arr1[] = { Interval(1, 3)
                      , Interval(7, 9)
                      , Interval(4, 6)
                      , Interval(10, 13)
                      };
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    int arr1_overlap_index = intervalsOverlap(arr1, arr1_size);
    if(arr1_overlap_index > -1) {
        cout << "Overlap at index " << arr1_overlap_index << endl;
    } else {
        cout << "No overlap" << endl;
    }
    if(intervalsOverlap1(arr1, arr1_size)) {
        cout << "Overlap" << endl;
    } else {
        cout << "No overlap" << endl;
    }

    // Example 2
    Interval arr2[] = { Interval(6, 8)
                      , Interval(1, 3)
                      , Interval(2, 4)
                      , Interval(4, 7)
                      };
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    int arr2_overlap_index = intervalsOverlap(arr2, arr2_size);
    if(arr2_overlap_index > -1) {
        cout << "Overlap at index " << arr2_overlap_index << endl;
    } else {
        cout << "No overlap" << endl;
    }
    if(intervalsOverlap1(arr2, arr2_size)) {
        cout << "Overlap" << endl;
    } else {
        cout << "No overlap" << endl;
    }

    return 0;
}


