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

// Space Complexity: O(n). This is because recursion on stack with index 0 1 2 3, then breaks at string length
// Time Complexity : O(2^n). Check recursion tree below
//            0                  2^0
//           / \
//          /   \
//         /     \
//        /       \
//       /         \
//      1           1            2^1
//     / \         / \
//    /   \       /   \
//   2     2     2     2         2^2
//  / \   / \   / \   / \
// 3   3 3   3 3   3 3   3       2^3
//
// Total recursion calls = 2^0 + 2^1 + 2^2 + 2^3 = 2^n

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
