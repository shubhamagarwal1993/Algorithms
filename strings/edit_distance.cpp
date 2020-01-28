#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//EDIT DISTANCE
// - INSERT
// - REMOVE
// - REPLACE


//simple recursion - trying all cases
int edit_distance(string str1, string str2, int str1_len, int str2_len) {
    if(str1_len == 0)
        return str2_len;

    if(str2_len == 0)
        return str1_len;

    //check if last character is same
    if(str1[str1_len-1] == str2[str2_len-1])
        return edit_distance(str1, str2, str1_len-1, str2_len-1);

    //if not same character, then try all 3 combinations
    return 1 + min( 
                min(
                    edit_distance(str1, str2, str1_len, str2_len-1), 
                    edit_distance(str1, str2, str1_len-1, str2_len)
                    ), 
                edit_distance(str1, str2, str1_len-1, str2_len-1)
                );
}

//dynamic - using 2d array
int edit_distance(string str1, string str2) {

    int str1_len = str1.length();
    int str2_len = str2.length();

    int dp[str1_len+1][str2_len+1];

    // Fill d[][] in bottom up manner
    for(int i = 0; i <= str1_len; i++) {
        for(int j = 0; j <= str2_len; j++) {
            if(i == 0)
                dp[i][j] = j;

            else if(j == 0)
                dp[i][j] = i;

            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
        }
    }

    return dp[str1_len][str2_len];
}

int main() {
/*
    //time O(3^m)
    string str1 = "temp";
    string str2 = "aaaa";
    cout << edit_distance(str1, str2, str1.length(), str2.length()) << endl;
*/

    //using dynamic - time O(mn)
    string str1 = "temper";
    string str2 = "zamp";
    cout << edit_distance(str1, str2) << endl;
    return 0;
}

