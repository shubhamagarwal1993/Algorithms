#include <iostream>
#include <unordered_map>

using namespace std;

// I    1
// V    5
// X    10
// L    50
// D    100
// M    1000

int romanToInt(string roman, unordered_map<char, int> romanToIntMap) {
    if(roman.length() == 0) {
        return 0;
    }

    if(roman.length() == 1) {
        return romanToIntMap[roman[0]];
    }

    // Flag is previous roman is already added
    bool already_added = false;
    int romanVal = 0;

    for(int i = 1; i < roman.length(); i++) {
        if(already_added) {
            already_added = false;
            continue;
        } else if(romanToIntMap[roman[i-1]] >= romanToIntMap[roman[i]]) {
            romanVal += romanToIntMap[roman[i-1]];
        } else {
            romanVal += (romanToIntMap[roman[i]] - romanToIntMap[roman[i-1]]);
            already_added = true;
        }
    }

    // check if last character of given roman is added
    if(!already_added) {
        romanVal += romanToIntMap[roman[roman.length() - 1]];
    }

    return romanVal;
}

int main() {
    //string roman = "";
    //string roman = "I";
    //string roman = "III";
    //string roman = "IV";
    //string roman = "VI";
    //string roman = "MDLXVI";
    string roman = "DMXLIV";

    // populate roman to int map
    unordered_map<char, int> romanToIntMap;
    romanToIntMap['I'] = 1;
    romanToIntMap['V'] = 5;
    romanToIntMap['X'] = 10;
    romanToIntMap['L'] = 50;
    romanToIntMap['D'] = 100;
    romanToIntMap['M'] = 1000;

    int romanIntValue = romanToInt(roman, romanToIntMap);
    if(romanIntValue <= 0) {
        cout << "Not Possible" << endl;
    } else {
        cout << "Roman: " << roman << ", Numberic value: " << romanIntValue << endl;
    }

    return 0;
}