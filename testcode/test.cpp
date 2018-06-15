#include <iostream>

using namespace std;

int charToIntVal(char c) {
    return (int)c;
}

char intToCharVal(int input) {
    return (char)input;
}

int main() {

    char temp = '#';
    cout << temp << ": " << charToIntVal(temp) << endl;
    int ascii = 85;
    cout << ascii << ": " << intToCharVal(ascii) << endl;

    return 0;
}
