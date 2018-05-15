// Given a string, find if the string follows a given pattern

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool patternMatch(string str, int str_size, int str_index, string pattern, int pattern_size, int pattern_index, unordered_map<char, string> &map) {

    if((str_index == str_size) && (pattern_index == pattern_size)) {
        return true;
    }

    if((str_index == str_size) || (pattern_index == pattern_size)) {
        return false;
    }

    char pattern_curr_char = pattern[pattern_index];

    // 2 cases - this char in pattern is seen before or not
    if(map.find(pattern_curr_char) != map.end()) {
        string temp_str = map[pattern_curr_char];
        int temp_str_len = temp_str.size();

        // get the string which should map the char
        string subStr = str.substr(str_index, temp_str_len);

        // compare the pattern character value from map and string from input
        // input string and map value should match
        if(subStr.compare(temp_str)) {
            return false;
        }

        // the input string and map values match, check for next pattern
        return patternMatch(str, str_size, str_index + temp_str_len, pattern, pattern_size, pattern_index+1, map);
    }

    // this char in pattern is not seen before
    for(int i = 1; i <= str_size - str_index; i++) {
        // consider substring that starts at str_index, and spans length(i is length in substr) and add it to map
        map[pattern_curr_char] = str.substr(str_index, i);

        if(patternMatch(str, str_size, str_index + i, pattern, pattern_size, pattern_index + 1, map)) {
            return true;
        }

        // backtrack - remove char from map 
        map.erase(pattern_curr_char);
    }

    return false;
}

int main() {
    string str = "TestmeTest";
    string pattern = "aba";

    int str_size = str.size();
    int pattern_size = pattern.size();

    if(str_size >= pattern_size) {
        // hashmap for pattern char to string
        unordered_map<char, string> map;
        if(patternMatch(str, str_size, 0, pattern, pattern_size, 0, map)) {
            // print the mappings
            for(auto it = map.begin(); it != map.end(); it++) {
                cout << it->first << "->" << it->second << endl;
            }
        } else {
            cout << "No solution" << endl;
        }
    }

    return 0;
}

