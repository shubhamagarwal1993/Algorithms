#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {

    // create n empty buckets
    vector<float> buckets[n];

    // put array elements in different buckets
    for(int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {

    // Bucket sort - sort floating point numbers ranging 
    // from 0.0 to 1.0 that are uniformly distributed across the range
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

