#include <iostream>

using namespace std;

string changeCase(string input, int index) {
    if(index < 0 || index >= input.size()) {
        return "";
    }

    if( (input[index] >= 'A') && (input[index] <= 'Z') ) {
        input[index] = input[index] + 32;
    } else if( (input[index] >= 'a') && (input[index] <= 'z') ) {
        input[index] = input[index] - 32;
    }
    return input;
}

void stringCombinations(string input, int index) {

    if(index == input.size()) {
        cout << input << endl;
        return;
    }

    stringCombinations(input, index+1);
    input = changeCase(input, index);
    stringCombinations(input, index+1);
}

int main() {
    stringCombinations("abc", 0);
    return 0;
}
