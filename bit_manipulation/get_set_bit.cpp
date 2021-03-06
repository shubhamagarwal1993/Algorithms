#include <iostream>

using namespace std;

// check if bit at kth position from right is set or not
bool getBit(int num, int k) {
    int mask = (1 << k);
    int result = num & mask;
    return result;
}

// set bit at kth position
int setBit(int num, int k) {
    int mask = (1 << k);
    int result = num | mask;
    return result;
}

// clears or makes bit at position k 0
int clearBit(int num, int k) {
    int mask = ~(1 << k);
    int result = num & mask;
    return result;
}

int updateBit(int num, int k, bool bitValue) {
    int value = bitValue ? 1 : 0;
    int mask = value << k;
    int result = clearBit(num, k) | mask;
    return result;
}

int main() {
    int num = 5; // 0 0 0 0 0 1 0 1
    int k = 2;   // 7 6 5 4 3 2 1 0

    // get value of bit at kth position
    cout << "Get bit " << getBit(num, k) << endl;

    // set value of bit at kth position
    k = 1;
    cout << setBit(num, k) << endl;

    // clears bit at kth position
    cout << clearBit(num, k) << endl;

    // updates bit at kth position
    cout << updateBit(num, k, true) << endl;

    return 0;
}

