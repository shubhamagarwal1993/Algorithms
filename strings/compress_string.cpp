// Run length encoding

#include <iostream>
#include <string>

using namespace std;

string compressString(string str) {

    if(str.length() == 0) {
        return str;
    }

    string ans = "";

    int count = 1;
    for(int i = 0; i < str.length() - 1; i++) {
        if(str[i] == str[i + 1]) {
            count++;
        } else {
            ans = ans + str[i];
            if(count > 1) {
                ans = ans + to_string(count);
            }
            count = 1;
        }
        if(ans.length() > str.length()) {
            return str;
        }
    }

    // last char has not been considered
//    if(str[str.length() - 1])

    return ans;
}

int main() {

//    string str = "";
//    string str = "a";
//    string str = "abc"
//    string str = "aaaabbc";
    string str = "aaaaaaaaaabbc";
    cout << "Compressed string : " << compressString(str) << endl;

    return 0;
}

