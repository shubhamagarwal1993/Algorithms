#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<vector<int> > myvec;

    for(int i = 0; i < 3; i++) {
        vector<int> temp;
        for(int j = 0; j < 5; j++) {
            temp.push_back(i);
        }
        myvec.push_back(temp);
    }

    for(int i = 0; i < myvec.size(); i++) {
        for(int j = 0; j < myvec[i].size(); j++) {
            cout << myvec[i][j];
        }
        cout << endl;
    }
}

// Average time to insert n+1 elements in vector of size n
// Vector grows in size as more elements are added to it
//
//
// Consider vector of size 4 - takes constant time to push 4 elements in vector
// Now push 5th element in vector
//     Create a new array of double the current size (8)
//     Copy the old elements to new array, and then add the new element. The next 3 push operations would take constant time
//
// In general if we consider an arbitrary number of pushes n + 1 to an array of size n, we notice that push operations take constant time except for the last one which takes O(N) time to perform the size doubling operation
//
// Since there were n + 1 operations total we can take the average of this and find that pushing elements onto the dynamic array takes:
//     (nO(1) + O(n)) / (n + 1) = O(1), constant time
