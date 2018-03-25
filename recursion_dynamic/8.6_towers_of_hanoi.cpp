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
}

int main() {

    //using recursion
    int num_of_disks = 4;
    towers_of_hanoi(num_of_disks, "origin", "buffer", "destination");

    return 0;
}
