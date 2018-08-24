#include <iostream>
#include <unordered_map>

using namespace std;

// I    1
// V    5
// X    10
// L    50
// D    100
// M    1000

void romanToInt(string roman) {
    if(roman.length() == 0) {
        cout << "Roman: " << roman << ", Numberic value: " << "0" << endl;
        return;
    }

    // populate roman to int map
    unordered_map<char, int> romanToIntMap;
    romanToIntMap['I'] = 1;
    romanToIntMap['V'] = 5;
    romanToIntMap['X'] = 10;
    romanToIntMap['L'] = 50;
    romanToIntMap['D'] = 100;
    romanToIntMap['M'] = 1000;

    if(roman.length() == 1) {
        cout << "Roman: " << roman << ", Numberic value: " << romanToIntMap[roman[0]] << endl;
        return;
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

    int romanIntValue = romanVal;
    if(romanIntValue <= 0) {
        cout << "Not Possible" << endl;
    } else {
        cout << "Roman: " << roman << ", Numberic value: " << romanIntValue << endl;
    }

    return;
}

int sub_digit(char num1, char num2, int i, char *c) {
    c[i++] = num1;
    c[i++] = num2;
    return i;
}

int digit(char ch, int n, int i, char *c) {
    for(int j = 0; j < n; j++) {
        c[i++] = ch;
    }
    return i;
}

void intToRoman(int int_val) {

    if(int_val <= 0) {
        cout << "Cannot find Roman for 0 and -ve numbers" << endl;
        return;
    }

    char c[10001];
    int i = 0;

    // string to concatenate 
    string ans = "";

    while(int_val != 0) {

        if(int_val >= 1000) {
            i = digit('M', int_val/1000, i, c);
            int_val = int_val%1000;
        } else if(int_val >= 500) {
            // To add base symbol to the character array
            if(int_val < 900) {
               // Add 'D' int_val/1000 times after index i
               i = digit('D', int_val/500, i, c);
               int_val = int_val%500;
            } else {
                // Add C and M after index i/.
                i = sub_digit('C', 'M', i, c);
                int_val = int_val%100 ;
            }
        } else if (int_val >= 100) {
            if (int_val < 400) {
                i = digit('C', int_val/100, i, c);
                int_val = int_val%100;
            }
 
            // To handle subtractive notation in case of int_val
            // having digit as 4 and adding corresponding base
            // symbol
            else
            {
                i = sub_digit('C','D',i,c);
                int_val = int_val%100;
            }
        }
 
        // If base value of int_val is greater than or equal to 50
        else if (int_val >= 50 )
        {
            // To add base symbol to the character array
            if (int_val < 90)
            {
                i = digit('L', int_val/50,i,c);
                int_val = int_val%50;
            }
 
            // To handle subtractive notation in case of int_val
            // having digit as 9 and adding corresponding base
            // symbol
            else
            {
                i = sub_digit('X','C',i,c);
                int_val = int_val%10;
            }
        }
        // If base value of int_val is greater than or equal to 10
        else if (int_val >= 10)
        {
            // To add base symbol to the character array
            if (int_val < 40)
            {
                i = digit('X', int_val/10,i,c);
                int_val = int_val%10;
            }
 
            // To handle subtractive notation in case of
            // int_val having digit as 4 and adding
            // corresponding base symbol
            else
            {
                i = sub_digit('X','L',i,c);
                int_val = int_val%10;
            }
        }
 
        // If base value of int_val is greater than or equal to 5
        else if (int_val >= 5)
        {
            if (int_val < 9)
            {
                i = digit('V', int_val/5,i,c);
                int_val = int_val%5;
            }
 
            // To handle subtractive notation in case of int_val
            // having digit as 9 and adding corresponding base
            // symbol
            else
            {
                i = sub_digit('I','X',i,c);
                int_val = 0;
            }
        }
 
        // If base value of int_val is greater than or equal to 1
        else if (int_val >= 1)
        {
            if (int_val < 4)
            {
                i = digit('I', int_val,i,c);
                int_val = 0;
            }
 
            // To handle subtractive notation in case of
            // int_val having digit as 4 and adding corresponding
            // base symbol
            else
            {
                i = sub_digit('I', 'V', i, c);
                int_val = 0;
            }
        }
    }
 
}

int main() {
    //string roman = "";
    //string roman = "I";
    //string roman = "III";
    //string roman = "IV";
    //string roman = "VI";
    //string roman = "MDLXVI";
    string roman = "DMXLIV";
    romanToInt(roman);

    int int_val = 944;
    intToRoman(int_val);

    return 0;
}

