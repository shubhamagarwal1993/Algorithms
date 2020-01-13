#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

bool areAnagram(string str1, string str2) {

    if(str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, int> compareMap;

    for(int i = 0; i < str1.length(); i++) {

        // look for str1 char in map
        unordered_map<char, int>::const_iterator itr = compareMap.find(str1[i]);
        if(itr == compareMap.end()) {
            // add char from str1 to map
            compareMap[str1[i]] = 1;
        } else {
            // increment count
            compareMap[str1[i]] += 1;
        }
    }

    for(int i = 0; i < str2.length(); i++) {

        // Remove str2 char from map
        unordered_map<char, int>::const_iterator itr = compareMap.find(str2[i]);
        if(itr == compareMap.end()) {
            // char not found in map, this strings are different
            return false;
        } else {
            // decrement count
            compareMap[str2[i]] -= 1;

            // remove char from map if count is 0
            if(compareMap[str2[i]] == 0) {
                compareMap.erase(str2[i]);
            }
        }
    }

    return compareMap.empty();
}

int main() {
    //string str1 = "abcd";
    string str1 = "aabcd";
    // string str2 = "eecbd";
    string str2 = "dcbaa";

    if(areAnagram(str1, str2)) {
        cout << "Anagram True" << endl;
    } else {
        cout << "Not anagram" << endl;
    }

    return 0;
}

