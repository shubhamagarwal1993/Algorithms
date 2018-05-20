#include <iostream>

using namespace std;

bool kthBitIs1(unsigned int num, int k) {
    int mask = 1 << k;
    int result = mask & num;
    return result != 0 ? true : false;
}

bool isPalindrome(unsigned int num) {

    int num_temp = num;
    int total_bits = 0;
    while(num_temp != 0) {
        total_bits++;
        num_temp = num_temp >> 1;
    }

    int right = 0;
    int left = total_bits - 1;

    while(left > right) {
        if(kthBitIs1(num, right) != kthBitIs1(num, left)) {
            return false;
        }
        right++;
        left--;
    }

    return true;
}

int main() {

    // binary representation 0000010001010001
    cout << isPalindrome(1105) << endl;
    return 0;
}
