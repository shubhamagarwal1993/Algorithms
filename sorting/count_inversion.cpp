#include<iostream>

using namespace std;

void printArray(int arr[], int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Inversion Count for an array indicates how far (or close) the array is from being sorted
 * If array is already sorted then inversion count is 0
 * If array is sorted in reverse order that inversion count is the maximum
 *
 * Time Complexity: O(n^2) two simple loops
 */
int getCountInversionNaive(int arr[], int arr_size) {

    //
    int inversion_count = 0;

    for(int i = 0; i < arr_size - 1; i++) {
        for(int j = i + 1; j < arr_size; j++) {
            if(arr[i] > arr[j]) {
                inversion_count++;
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }

    return inversion_count;
}

/**
 * In merge process, let i is used for indexing left sub-array and j for right sub-array
 * At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions
 * because left and right subarrays are sorted, so all the remaining elements 
 * in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]
 */
int merge(int arr[], int sorted_arr[], int arr_size, int l, int mid, int r) {

    // count of inversions
    int inversion_count = 0;

    // make temp arrays to hold data as arr will be replaced by sorted data
    int arr_l_index = l;
    int arr_r_index = mid + 1;
    int arr_index = l;

    while((arr_l_index <= mid) && (arr_r_index < arr_size)) {

        if(arr[arr_l_index] <= arr[arr_r_index]) {
            sorted_arr[arr_index] = arr[arr_l_index];
            arr_l_index++;
        } else {
            sorted_arr[arr_index] = arr[arr_r_index];
            arr_r_index++;

            inversion_count += (mid - arr_l_index);
        }
        arr_index++;
    }

    while(arr_l_index <= mid) {
        sorted_arr[arr_index] = arr[arr_l_index];
        arr_index++;
        arr_l_index++;
    }

    while(arr_r_index < arr_size) {
        sorted_arr[arr_index] = arr[arr_r_index];
        arr_index++;
        arr_r_index++;
    }

    // Copy back the merged elements to original array
    for(int i = l; i <= r; i++) {
        arr[i] = sorted_arr[i];
    }

    return inversion_count;
}

/**
 * Inversion Count for an array indicates how far (or close) the array is from being sorted
 * 
 * We can count for inversions in the merge step
 * If we know inversion in left and right array, we can add them to the inversions in merge
 *
 * Time Complexity: O(nlogn)
 */
int getCountInversionMergeSort(int arr[], int sorted_arr[], int arr_size, int l, int r) {

    // this will keep count of inversions
    int inversion_count = 0;

    // we need to create another array to store the sorted array
    // Cannot replace elements in arr cos count of inversions will be wrong as it is sorted
    if(l < r) {
        int mid = (l + r)/2;
        inversion_count = getCountInversionMergeSort(arr, sorted_arr, arr_size, l, mid);
        inversion_count += getCountInversionMergeSort(arr, sorted_arr, arr_size, mid+1, r);
        inversion_count += merge(arr, sorted_arr, arr_size, l, mid, r);
    }

    return inversion_count;
}

int main() {

    int arr[] = {1, 20, 6, 4, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int count_inversions = getCountInversionNaive(arr, arr_size);
    cout << "Number of inversions are: " << count_inversions << endl;

    cout << "--------" << endl;
    int left_index = 0;
    int right_index = arr_size - 1;
    int *sorted_arr = new int[arr_size];
    count_inversions = getCountInversionMergeSort(arr, sorted_arr, arr_size, left_index, right_index);
    cout << "Number of inversions are: " << count_inversions << endl;
    return 0;
}

