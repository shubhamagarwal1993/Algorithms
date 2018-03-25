#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo>
using namespace std;

double power(float x, int y) {

    // base case - can handle other things like x = 0 will be 0 or infinite
    if(y == 0) {
        return 1;
    }

    float temp = power(x, y/2);
    if(y % 2 == 0) {
        return temp * temp;
    } else {
        if (y > 0) {
            return x * temp * temp;
        } else {
            return (temp * temp)/x;
        }
    }

    return 0;
}

int main() {

    // function to find x^y
    float x = 2;
    int y = -3;

    // Runtime O(log n) and Space O(1)
    cout << "Power = " << power(x, y) << endl;
    return 0;
}

