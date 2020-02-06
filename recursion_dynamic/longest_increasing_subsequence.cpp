#include <vector>
#include <iostream>

using namespace std;

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
            tailIndices[len] = i;
            len += 1;
        } else {
            int pos = getCeilIndex(arr, tailIndices, -1, len - 1, arr[i]);
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }

    for(int i = 0; i < prevIndices.size(); i++) {
        cout << prevIndices[i] << " ";
    }
    cout << endl;

    for(int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return len;
}

int main() {

    // Time complexity O(n logn)
    int arr[] = {2, 3, 4, 8, 1, 2, 3, 4, 5, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int len = LIS_vector(arr, arr_size);
    cout << "Length of longest subsequence: " << len << endl;

    return 0;
}

