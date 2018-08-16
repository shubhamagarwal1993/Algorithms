#include <vector>
#include <iostream>

using namespace std;

int LIS(int arr[], int arr_size) {

    // will store index here for increasing subsequence here
    int lis[arr_size];
    for(int i = 0; i < arr_size; i++) {
        lis[i] = 1;
    }

    // loop over and give higher index for greater values
    for(int i = 1; i < arr_size; i++) {
        for(int j = 0; j < i; j++) {
            if((arr[i] > arr[j]) && (lis[i] < lis[j]+1)) {
                lis[i] = lis[j]+1;
            }
        }
    }

    // Get the highest index - that will be the size of the lis
    int max = 0;
    vector<int> lis_vec;
    for(int i = 0; i < arr_size; i++) {
        if(max < lis[i]) {
            max = lis[i];
            lis_vec.push_back(arr[i]);
        }
    }

    // print lis
    for(int i = 0; i < lis_vec.size(); i++) {
        cout << lis_vec[i] << " ";
    }
    cout << endl;

    return max;
}

// binary search
int ceilIndex(vector<int> &vec, int l, int r, int val) {
    while(l < r-1) {
        int mid = (r + l) / 2;
        if(vec[mid] >= val) {
            r = mid;
        } else {
            l = mid;
        }
    }

    // send the greatest value before current value
    return r;
}

int LIS_vector_size(vector<int> &vec) {

    if(vec.size() == 0) {
        return 0;
    }

    // make a vector of size number of elements and initialize all to 0
    // make first element as first element of lis
    vector<int> tail(vec.size(), 0);
    tail[0] = vec[0];

    // keep track of what length is filled up to now
    int length = 1;

    for(int i = 1; i < vec.size(); i++) {
        // smaller than smallest element yet
        if(vec[i] < tail[0]) {
            tail[0] = vec[i];
        // larger than largest element yet - make new list (clone) and add current element
        } else if(vec[i] > tail[length-1]) {
            tail[length++] = vec[i];
        // find new index to insert current element
        } else {
            // we choose -1 for left index to avoid infinite while loop in binary search
            int index = ceilIndex(tail, -1, length-1, vec[i]);
            tail[index] = vec[i];
            // since length does not change, a
        }
    }

    for(int i = 0; i < length; i++) {
        cout << tail[i] << " ";
    }
    cout << endl;

    return length;
}

int getCeilIndex(int arr[], vector<int> &tailIndices, int l, int r, int key) {
    while(r - l > 1) {
        int mid = l + (r - l)/2;
        if(arr[tailIndices[mid]] >= key) {
            r = mid;
        } else {
            l = mid;
        }
    }

    return r;
}

int LIS_vector(int arr[], int arr_size) {

    vector<int> tailIndices(arr_size, 0);
    vector<int> prevIndices(arr_size, -1);

    int len = 1;
    for(int i = 1; i < arr_size; i++) {

        if(arr[i] < arr[tailIndices[0]]) {
            tailIndices[0] = i;
        } else if(arr[i] > arr[tailIndices[len - 1]]) {
            prevIndices[i] = tailIndices[len-1];
            tailIndices[len++] = i;
        } else {
            int pos = getCeilIndex(arr, tailIndices, -1, len - 1, arr[i]);
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }

    for(int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return len;
}

int main() {

    // Time complexity O(n^2)
    //int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
    int arr[] = {5, 6, 7, 8, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << LIS(arr, arr_size) << endl;

    // Time complexity O(n logn)
    vector<int> vec;
    vec.assign(arr, arr+arr_size);
    cout << LIS_vector_size(vec) << endl;

    // Time complexity O(n logn)
    cout << LIS_vector(arr, arr_size) << endl;

    return 0;
}

