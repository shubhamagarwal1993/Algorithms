#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unordered_map>
using namespace std;

// Get the longest substring
int longest_substring(string str) {

    if(str.length() == 0 || str.length() == 1) {
        return str.length();
    }

    int max_len = 0;
    int curr_len = 0;

    // map to maintain 
    unordered_map<char, int> mymap;
    for(int i = 0; i < str.length(); i++) {
        
        // if curr character in map
        if(mymap.find(str[i]) != mymap.end()) {
            // check if char in current substring
            if(i - curr_len >= mymap[str[i]]) {
                // get the max len
                if(curr_len > max_len)
                    max_len = curr_len;
                curr_len = i - mymap[str[i]];
            } else {
                // if character not in current substring
                // put character in map
                mymap[str[i]] = i;

                // increase curr length
                curr_len += 1;
            }
        } else {
            // put character in map
            mymap[str[i]] = i;

            // increase curr length
            curr_len += 1;
        }
        cout << mymap.find(str[i])->first << " " << mymap.find(str[i])->second << " " << curr_len << endl;
    }

    if(curr_len > max_len)
        return curr_len;
    return max_len;
}

int main() {
    string str = "ABCDEFABCOO";

    //find longest substring
    cout << longest_substring(str) << endl;

    return 0;
}
