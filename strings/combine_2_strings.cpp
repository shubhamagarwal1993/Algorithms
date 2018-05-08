#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool iscombined_iterative(string str1, string str2, string str3) {
    if(str1.length() + str2.length() != str3.length())
        return false;

    if(str1.length() == 0 || str2.length() == 0) {
        if (str3 == str1 + str2)
            return true;
        else
            return false;
    }

    int j = 0, k = 0;            //j for str1, k for str2

    for(int i = 0; i < str3.length(); i++) {
        if(str3[i] == str1[j]) {
            j++;
            continue;
        } else if(str3[i] == str2[k]) {
            k++;
            continue;
        } else {
            return false;
        }
    }

    return true;
}

bool iscombined_recursion(string str1, string str2, string str3) {
    if(str1.length() + str2.length() != str3.length())
        return false;

    if(str1.length() == 0 || str2.length() == 0) {
        if(str3 == str1 + str2)
            return true;
        else
            return false;
    }

    if(str1[0] != str3[0] && str2[0] != str3[0])
        return false;

    if(str1[0] == str3[0] && iscombined_recursion(str1.substr(1), str2, str3.substr(1)))
        return true;

    if(str2[0] == str3[0] && iscombined_recursion(str1, str2.substr(1), str3.substr(1)))
        return true;

    return false;
}

/*
bool iscombined_dynamic(string str1, string str2, string str3, set<int> myset) {
    if(str1.length() + str2.length() != str3.length())
        return false;

    if(str1.length() == 0 || str2.length() == 0) {
        if (str3 == str1 + str2)
            return true;
        else
            return false;
    }

    if(str1[0] != str3[0] && str2[0] != str3[0])
        return false;

    if (str1[0] == str3[0] && iscombined_dynamic(str1.substr(1), str2, str3.substr(1), myset))
        return true;

    if (str2[0] == str3[0] && iscombined_dynamic(str1, str2.substr(1), str3.substr(1), myset))
        return true;

    return false;
}
*/

int main() {
/*
    //using recursion only
    string str1 = "abc";
    string str2 = "def";
    string str3 = "dacbef";
    cout << iscombined_recursion(str1, str2, str3) << endl;
*/
/*    DONT SEE THE POINT OF DYNAMIC HERE -> NOT WORKING AS WELL.
    //using dynamic
    string str1 = "abc";
    string str2 = "def";
    string str3 = "dacbef";

    set<int> myset;
    cout << iscombined_dynamic(str1, str2, str3, myset) << endl;    
*/

    //using iterative method
    string str1 = "abc";
    string str2 = "dbf";
    string str3 = "dabbcf";
    cout << iscombined_iterative(str1, str2, str3) << endl;
    
    return 0;
}

