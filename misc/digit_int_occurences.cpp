#include <iostream>

using namespace std;

// num - E.g. 746728
// digit - E.g. 7
int occurences(int num, int digit) {

    if(num < digit) {
        return 0;
    }

    if(num%10 == digit) {
        return occurences(num/10, digit) + 1;
    }

    return occurences(num/10, digit);
}

int main() {
	int digit = 7;
    cout << occurences(2377473, digit) << endl;
	return 0;
}

