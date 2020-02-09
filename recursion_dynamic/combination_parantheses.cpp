#include <iostream>

using namespace std;

void print_parentheses(int index, int leftRem, int rightRem, char char_arr[]) {
    if(leftRem < 0 || rightRem < leftRem) {
        return;
    }

    if(leftRem == 0 && rightRem == 0) {
        for(int i = 0; i < 6; i++) {
            cout << char_arr[i];
        }
        cout << endl;
    }

    if(leftRem > 0) {
        char_arr[index] = '(';
        print_parentheses(index + 1, leftRem - 1, rightRem, char_arr);
    }

    if(rightRem > 0) {
        char_arr[index] = ')';
        print_parentheses(index + 1, leftRem, rightRem - 1, char_arr);
    }
}

int main() {

    int index = 0;
    int leftRem = 3;
    int rightRem = 3;
    char char_arr[6];

    print_parentheses(index, leftRem, rightRem, char_arr);
    return 0;
}
