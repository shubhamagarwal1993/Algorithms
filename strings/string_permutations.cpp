#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

//  swap values for x and y
void swap(char &x, char &y) {
    char temp;
    temp = x;
    x = y;
    y = temp;
}

//print permutations of string using recursion with duplicates
void permute_recursion_with_duplicates(string a, int l_index, int r_index) {
    if (l_index == r_index)
        cout << a << endl;
    else {
        for (int i = l_index; i <= r_index; i++) {
            swap( a[l_index], a[i]);
            permute_recursion_with_duplicates(a, l_index+1, r_index);
            swap( a[l_index], a[i]);
        }
    }
}

//print permutations of string using recursion without duplicates
void permute_recursion_without_duplicates(string a, int l_index, int r_index) {
    if (l_index == r_index)
        cout << a << endl;
    else {
        for (int i = l_index; i <= r_index; i++) {
            if((i == l_index) || (a[i] != a[i-1])) {
                swap( a[l_index], a[i]);
                permute_recursion_without_duplicates(a, l_index+1, r_index);
                swap( a[l_index], a[i]);
            }
        }
    }
}

int main() {
    // Using recursion
    // Time complexity - O(n*n!)
    // requires O(n) time to print a permutation, total n! permutations
    string str = "BAA";
    int length = str.length();
    // print permutations in lexicographical order
    std::sort(str.begin(), str.end());

    // prints duplicates
    permute_recursion_with_duplicates(str, 0, length-1);
    cout << endl;

    // no duplicates
    permute_recursion_without_duplicates(str, 0, length-1);
    cout << endl;

    return 0;
}

