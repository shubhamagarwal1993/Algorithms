#include <iostream>

using namespace std;

bool bitValueAtK(unsigned int num, int k) {
    int mask = 1 << k;
    int result = mask & num;
    return result != 0 ? true : false;
}

bool isPalindrome(unsigned int num) {

    // assume long int
    int unsigned_int_max_bits = 32;

    // get total bits num needs, excluding leading 0s
    int total_bits = 0;
    int num_temp = num;
    while(num_temp != 0) {
        total_bits++;
        num_temp = num_temp >> 1;
    }

    // Count ending 0s
    int total_trailing_0s = 0;
    num_temp = num;
    while(!(1 & num_temp)) {
        total_trailing_0s++;
        num_temp = num_temp >> 1;
    }

    // Check if we have enough space to put 0s in the front of the num
    if(total_bits + total_trailing_0s > unsigned_int_max_bits) {
        return false;
    }

    // set pointers on num
    int right = 0;
    int left = total_bits + total_trailing_0s - 1;

    while(left > right) {
        if(bitValueAtK(num, right) != bitValueAtK(num, left)) {
            return false;
        }
        right++;
        left--;
    }

    return true;
}

int main() {

    // binary representation 0000010001010001000
    unsigned int num = 8840;
    if(isPalindrome(num)) {
        cout << "bit representation of " << num << " is a palindrome" << endl;
    } else {
        cout << "bit representation of " << num << " is not a palindrome" << endl;
    }

    return 0;
}
