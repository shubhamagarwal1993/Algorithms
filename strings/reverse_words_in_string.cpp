#include <iostream>

using namespace std;

void reverse(string &str, int left, int right) {

    if(str.empty()) {
        return;
    }

    for(int i = 0; i < (right+1-left)/2; i++) {
        char temp = str[left+i];
        str[left+i] = str[right-i];
        str[right-i] = temp;
    }

    return;
}

void reverse_words(string &str) {

    int l = 0;
    int r = 0;

    for(int i = 0; i < str.length(); i++) {

        if(str[i] == ' ') {
            r = i-1;
            reverse(str, l, r);
            l = i+1;
        } else if(i == str.length()-1) {
            r = i;
            reverse(str, l, r);
        }
    }
    return;
}

int main() {
    string str = "abc dfg erwe";
    cout << "Original String: " << str << endl;
    reverse(str, 0, str.length()-1);
    cout << "Reversed String: " << str << endl;
    reverse_words(str);
    cout << "Reversed words : " << str << endl;
    return 0;
}

