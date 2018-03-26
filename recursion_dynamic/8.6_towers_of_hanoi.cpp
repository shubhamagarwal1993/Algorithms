#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

//using recursion
void towers_of_hanoi(int num_of_disks, string origin, string buffer, string destination) {
    //base case
    if (num_of_disks == 1) {
        cout << "move disk " << num_of_disks << " from " << origin << " to  " << destination << endl;
        return;
    }

    towers_of_hanoi(num_of_disks-1, origin, destination, buffer);
    cout << "move disk " << num_of_disks << " from " << origin << " to  " << destination << endl;
    towers_of_hanoi(num_of_disks-1, buffer, origin, destination);

    // Finding time complexity
    // T(n) = T(n-1) + O(1) + T(n-1)
    // T(n) = T(n-1) + 1 + T(n-1)
    // T(0) = 0 for base case
    //
    // n   : 0 1 2 3  4  5  6
    // T(n): 0 1 3 7 15 31 63 => 63 comes from 31 + 1 + 31 by pluggin in above recursion
    // T(n) = O((2^n) - 1) = O(2^n)
}

int main() {

    //using recursion
    int num_of_disks = 4;
    towers_of_hanoi(num_of_disks, "origin", "buffer", "destination");

    return 0;
}
