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
        //count = count || (str[i] >> 1);
        cout << (int)str1[i] - 'a' << " ";
    }
    cout << endl;

    cout << checker << endl;
    checker = checker || (1 << ((int)str1[0] - 'a'));
    cout << checker << endl;
 
    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
//    if (str1[i] || str2[i]) {
//        return false;
//    }
 
    // See if there is any non-zero value in count array
//    for (i = 0; i < NO_OF_CHARS; i++) {
//        if(count[i]) {
//            return false;
//        }
//    }

    return true;
}

int main() {
    string str1 = "abcd";
    string str2 = "dcba";

    // check if strings are anagram
    if(areAnagram(str1, str2)) {
        cout << "Anagram True" << endl;
    } else {
        cout << "Not anagram" << endl;
    }

    return 0;
}

