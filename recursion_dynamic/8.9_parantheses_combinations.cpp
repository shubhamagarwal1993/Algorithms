#include <iostream>

using namespace std;

void printParentheses(int index, int count, int open, int close, string str) {
    // reached end of current permutation
    cout << "string - " << str << endl;
    if(close == count) {
        cout << str << endl;
    } else {
        if(open > close) {
            str[index] = '}';
            printParentheses(index+1, count, open, close+1, str);
        }

        if(open < count) {
            if(index > str.size() - 1) {
                str = str + "{";
            } else {
                str[index] = '{';
            }
            printParentheses(index+2, count, open+1, close, str);
        }
    }
}

void print_parentheses(int index, int leftRem, int rightRem, char char_arr[]) {
    if(leftRem < 0 || rightRem < leftRem) return;

    if(leftRem == 0 && rightRem == 0) {
        for(int i = 0; i < 6; i++) {
            cout << char_arr[i];
        }
        cout << endl;
    } else {
        char_arr[index] = '(';
        print_parentheses(index + 1, leftRem - 1, rightRem, char_arr);

        char_arr[index] = ')';
        print_parentheses(index + 1, leftRem, rightRem - 1, char_arr);
    }
}

int main() {

    int index = 0;
    int count = 3;
    int open = 0;
    int close = 0;
    string str = "";
    char char_arr[4];
    //printParentheses(index, count, open, close, str);
    print_parentheses(index, 3, 3, char_arr);
    return 0;
}
