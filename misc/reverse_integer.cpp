#include <iostream>

using namespace std;

int reverseInt(int input, int input_size) {

    for(int i = 0; i < input_size; i++) {
        int last_num = input%10;
        cout << last_num << endl;
        input = input/10;
        cout << input << endl;
        for(int j = 0; j < input_size-1; j++) {
            last_num = last_num*10;
        }
        cout << last_num << endl;
        input = input + last_num;
        cout << input << endl;
        cout << "==========" << endl;
    }
    return input;
}

int main() {
    int reversedInt = reverseInt(123, 3);
    cout << reversedInt << endl;
    return 0;
}
