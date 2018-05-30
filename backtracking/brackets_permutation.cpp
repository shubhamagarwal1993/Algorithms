# include<iostream>

using namespace std;

void printParenthesis(int pos, int n, int open, int close, char str[]) {

    if(close == n) {
        for(int i = 0; i < 2*n; i++) {
            cout << (char)str[i] << " ";
        }
        cout << endl;
        return;
    }

    if(open < n) {
        str[pos] = '{';
        printParenthesis(pos+1, n, open+1, close, str);
    }

    if(open > close) {
        str[pos] = '}';
        printParenthesis(pos+1, n, open, close+1, str);
    } else {
        return;
    }
}

void printParenthesis(int n) {
    if(n > 0) {
        char str[n];
        printParenthesis(0, n, 0, 0, str);
    }

    return;
}

int main() {

    int n = 3;
    printParenthesis(n);

    return 0;
}

