// Happy numbers are numbers whose digits squared add up to 1
// E.g 23 -> 2^2 + 3^2 => 4 + 9 = 13 => 1^2 + 3^2 => 1 + 9 = 10 => 1^2 + 0^2 => 1 + 0 = 1
// E.g 12 -> 1^2 + 2^2 => 1 + 4 = 5

#include <iostream>
#include <set>

using namespace std;

int getSqSumOfDigits(int abc) {

    int sq = 0;
    while(abc > 0) {
        int digit = abc % 10;
        sq += digit * digit;
        abc = abc / 10;
    }

    return sq;
}

// Repeatedly sum squares of digits
// While doing so, we keep track of visited numbers using a hash
// If we reach 1, we return true
// Else if we reach a visited a number, we return false
bool isHappy(int num) {

    set<int> sq_sum;
    sq_sum.insert(num);

    while(1) {

        if(num == 1) {
            return true;
        }

        num = getSqSumOfDigits(num);

        // This number has been seen before
        if(sq_sum.find(num) != sq_sum.end()) {
            return false;
        }

        // number not seen before, insert in map
        sq_sum.insert(num);
    }
    return false;
}

int main() {

    cout << isHappy(12) << endl;
    cout << isHappy(23) << endl;
    return 0;
}
