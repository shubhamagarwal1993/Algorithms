#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <unordered_map>
using namespace std;

// Get the longest substring
int longest_substring(string str) {

    if(str.length() == 0 || str.length() == 1)
        return str.length();

    int max_len = 0;
    int curr_len = 0;

    unordered_map<char, int> mymap;
    // loop over string
    for(int i = 0; i < str.length(); i++) {
        
        // if curr character in map
        if(mymap.find(str[i]) != mymap.end()) {
            // cout << mymap.find(str[i])->first << endl;
            // cout << mymap.find(str[i])->second << endl;
            // cout << curr_len << endl;
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
