#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

// check if 2 strings are anagram
bool areAnagram(string str1, string str2) {

    // Create two count arrays and initialize all values as 0
    int checker = 0;

    for(int i = 0; str1[i] && str2[i]; i++) {

        // get position in str1 to flip
        int k = 1 << ((int)str1[i] - 'a');

        // flip bit at k
        checker ^= k;

        // get position in str2 to flip
        k = 1 << ((int)str2[i] - 'a');

        // flip bit at k
        checker ^= k;
    }

    return (checker == 0) ? 1 : 0;
}

int main() {
    string str1 = "abcd";
    string str2 = "acbd";

    // check if strings are anagram
    if(areAnagram(str1, str2)) {
        cout << "Anagram True" << endl;
    } else {
        cout << "Not anagram" << endl;
    }

    return 0;
}

