#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

bool areAnagram(string str1, string str2) {

    unordered_map<char, int> compareMap;

    for(int i = 0; str1[i] && str2[i]; i++) {

        // add chars from str1
        compareMap[str1[i]]++;

        // subtract chars from str2
        compareMap[str2[i]]--;
    }

    return compareMap.empty();
}

int main() {
    //string str1 = "abcd";
    string str1 = "aabcd";
    string str2 = "eecbd";

    if(areAnagram(str1, str2)) {
        cout << "Anagram True" << endl;
    } else {
        cout << "Not anagram" << endl;
    }

    return 0;
}

