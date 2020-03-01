// compile using g++ -std=c++0x 2_3_4_array_sum.cpp
//
// Given array, find 2 numbers that sum up to k
// Given array, find 3 numbers that sum up to k
// Given array, find 4 numbers that sum up to k

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void two_sum(int arr[], int arr_size, int sum) {

    // num in arr and count of it
    unordered_map<int, int> mymap;

    int count = 0;
    for(int i = 0; i < arr_size; i++) {
        int temp = sum - arr[i];
        if(temp >= 0 && mymap[temp] >= 1) {
            for(int j = 0; j < mymap[temp]; j++) {
                count++;
                cout << "Pair with given sum " << sum << " is " << arr[i] << ", " << temp << endl;
            }
        }
        mymap[ arr[i] ] ++;
    }
    cout << count << endl;
}

void three_sum(int arr[], int arr_size, int sum) {
    int left, right;
    sort(arr, arr + arr_size);

    for (int i = 0; i < arr_size-2; i++) {
        left = i+1;
        right = arr_size - 1;

        while(left < right) {
            if (arr[i] + arr[left] + arr[right] == sum) {
                cout << "triplet with given sum " << sum << " is " << arr[i] << ", " << arr[left] << ", " << arr[right] << endl;
                left++;
            } else if(arr[i] + arr[left] + arr[right] < sum) {
                left++;
            } else {
                right--;
            }
        }
    }
}

#include <iostream>

using namespace std;

class Triplet {
public:
    int first;
    int second;
    int third;

    Triplet(int i, int j, int k) {
        this->first = i;
        this->second = j;
        this->third = k;
    }
};

/**
 * Find unique triplets that sum up to a given value
 */
bool findTriplets(int arr[], int arr_size, int sum) {

    // Vector to store all unique triplets
    vector<Triplet> triplets;

    // map to store already found triplets to avoid duplication
    unordered_set<string> uniqTriplets;

    // Variable used to hold triplet converted to string form
    string triplet_key;

    // Sort the input array
    sort(arr, arr + arr_size);

    // i will be the first element
    for(int i = 0; i < arr_size - 2; i++) {

        // j will be the second element, k the third element
        int j = i + 1;
        int k = arr_size - 1;

        while(j < k) {

            if(arr[i] + arr[j] + arr[k] == sum) {
                triplet_key = to_string(arr[i]) + " : " + to_string(arr[j]) + " : " + to_string(arr[k]);
                
                // if this triplet has not been seen before
                if(uniqTriplets.find(triplet_key) == uniqTriplets.end()) {
                    uniqTriplets.insert(triplet_key);
                    Triplet newTriplet(arr[i], arr[j], arr[k]);
                    triplets.push_back(newTriplet);
                }

                // continue for more triplets with current i

                j++;
                k--;
            } else if(arr[i] + arr[j] + arr[k] > sum) {
                k--;
            } else {
                j++;
            }
        }
    }

    if(triplets.size() == 0) {
        return false;
    }

    // Print all unique triplets stored in vector
    for(int i = 0; i < triplets.size(); i++) {
        cout << "[" << triplets[i].first << ", " << triplets[i].second << ", " << triplets[i].third <<"], " << endl;
    }

    return true;
}

class x_y {
    public:
        int sum;
        int x;
        int y;
};

bool comp(x_y const & a, x_y const & b) {
    return a.sum < b.sum;
}

bool not_repeat(x_y a, x_y b) {
    bool res = true;
    if((a.x == b.x && a.y == b.y) || (a.x == b.y && a.y == b.x)) {
        res = false;
    }

    return res;
}

void four_sum(int arr[], x_y temp_arr[], int arr_size, int temp_arr_size, int final_sum) {
    int k = 0;
    for (int i = 0; i < arr_size-1; i++) {
        for (int j = i+1; j < arr_size; j++) {
            temp_arr[k].sum = arr[i]+arr[j];
            temp_arr[k].x = arr[i];
            temp_arr[k].y = arr[j];
            k++;
        }
    }

    std::sort(temp_arr, temp_arr+temp_arr_size, comp);

    //for(int i = 0; i < temp_arr_size; i++) {
    //    cout << "(" << temp_arr[i].x << ", " << temp_arr[i].y << ") " << "-> " <<  temp_arr[i].sum << endl;
    //}

    int l = 0, r = temp_arr_size-1;
    while(l < r) {
        if(temp_arr[l].sum + temp_arr[r].sum == final_sum) {
            if(not_repeat(temp_arr[l], temp_arr[r])) {
                cout << final_sum << " = " << temp_arr[l].x << ", " << temp_arr[l].y << ", " << temp_arr[r].x << ", " << temp_arr[r].y << endl;
                l++;
            } else {
                r--;
            }
            l++;
        } else if(temp_arr[l].sum + temp_arr[r].sum < final_sum) {
            l++;
        } else {
            r--;
        }
    }
}

int main() {

    // 2 sum
    int arr[] = {1, 4, 45, 10, 6, 8, 8, 8, 4, 4, 10, 12};
    // int arr[] = {1, 1, 1, 1, 1, 1};
    int sum = 16;
    int arr_size = sizeof(arr)/sizeof(arr[1]);
    two_sum(arr, arr_size, sum);

/*
    // 3 sum
    int arr[8] = {1, 4, 45, 6, 10, 8, 19, 2};
    int sum = 22;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    three_sum(arr, arr_size, sum);
*/

    // 3 sum - unique numbers only
    //int arr[8] = {1, 4, 45, 6, 10, 8, 19, 2};
    //int sum = 22;
    //int arr_size = sizeof(arr)/sizeof(arr[0]);
    //if(!findTriplets(arr, arr_size, sum)) {
    //    cout << "No triplets can be formed.";
    //}


    // 4 sum
    /*
     * int arr[9] = {10, 20, 30, 40, 10, 1, 2, 25, 16};
     * int final_sum = 91;
     * int arr_size = sizeof(arr)/sizeof(arr[0]);
     * int temp_arr_size = arr_size*(arr_size-1)/2;
     * x_y temp_arr[temp_arr_size];                    //will store all sum pairs here
     * four_sum(arr, temp_arr, arr_size, temp_arr_size, final_sum);
     */

    return 0;
}



