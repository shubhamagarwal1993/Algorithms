#include <iostream>

using namespace std;

bool isUnique(string str) {
    int checker = 0;        // has 32 bits, so 32 characters on or off switch

    for(int i = 0; i < str.length(); i++) {
        cout << "char-" << str[i];
        int val = str[i] - 'a';
        cout << " " << "val-" << val;

        // check if char exists
        cout << " " << "checker-" << checker;
        cout << " " << "final1-" << (checker & (1 << val));
        cout << " " << "final2-" << (checker && (1 << val)) << endl;
        if((checker & (1 << val)) > 0) {
            return false;
        }

        // put char in checker if it does not exist
        checker = checker || (1 << val);
    }
    return true;
}

int main() {
    bool val = isUnique("abca");
    cout << "unique - " << val << endl;
    return 0;
}

