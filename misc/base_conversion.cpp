#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int charToIntVal(char c) {
    if(c >= '0' && c <= '9') {
        return (int)c - '0';
    } else {
        return (int)c - 'A' + 10;
    }
}

char intToCharVal(int input) {
    if(input >= 0 && input <= 9) {
        return (char)(input + '0');
    } else {
        return (char)(input + 'A' - 10);
    }
}

vector<char> convertDecimalToBase(int base, int num) {
    // store the result
    vector<char> digits;

    while(num > 0) {
        int remainder = num % base;
        digits.push_back(intToCharVal(remainder));
        num = num / base;
    }

    // stored in revere order as remainder is pushed in first
    std::reverse(digits.begin(), digits.end());
    return digits;
}

int convertBaseToDecimal(int base, char *input) {

    int ans = 0;
    int input_len = strlen(input);

    for(int i = input_len - 1; i >= 0; i--) {
        ans += charToIntVal(input[i]) * std::pow(base, input_len - 1 - i);
    }
    return ans;
}

void convertDecimalToBaseHelper() {
    int base = 62;
    int input = 125;
    vector<char> convertedValue = convertDecimalToBase(base, input);
    for(int i = 0; i < convertedValue.size(); i++) {
        cout << convertedValue[i];
    }
    cout << endl;
}

void convertBaseToDecimalHelper() {
    int base = 62;
    char input[] = "21";
    cout << convertBaseToDecimal(base, input);
    cout << endl;
}

// Driver Program to test above function
int main() {

    convertDecimalToBaseHelper();
    convertBaseToDecimalHelper();

	return 0;
}

