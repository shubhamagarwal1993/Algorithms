#include <iostream>

using namespace std;

// only works for ints
void swapIntInPlace(int a, int b) {
    // store difference in a
    a = b - a;
    // b becomes a
    b = b - a;
    // a becomes b
    a = b + a;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return;
}

template <class T>
void swapInPlace(T a, T b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return;
}

int main() {

    int a_orig = 2;
    int b_orig = 5;
    swapIntInPlace(a_orig, b_orig);
    swapInPlace(a_orig, b_orig);
    swapInPlace<int>(a_orig, b_orig);
	return 0;
}

