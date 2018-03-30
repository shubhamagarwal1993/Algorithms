#include <iostream>

using namespace std;

void sq_root(int num) {

    if(num == 0 || num == 1) {
        cout << "sq root = " << num << endl;
        return;
    }

    int sq_root = 0;
    for(int i = 1; i <= num; i++) {
        if(i * i == num) {
            sq_root = i;
        } else if(i * i > num) {
            sq_root = i - 1;
            break;
        }
    }

    cout << "sq root = " << sq_root << endl;
    return;
}

void sq_root_binary(int num, int l, int r) {
    if(num == 0 || num == 1) {
        cout << "sq root = " << num << endl;
        return;
    }

    int sq_root = 0;
    while(r >= l) {
        int mid = (l/2) + (r/2);
        if(mid * mid == num) {
            sq_root = mid;
            break;
        } else if(mid * mid > num) {
            r = mid - 1;
        } else {
            l = mid + 1;
            sq_root = mid;
        }
    }

    cout << "sq root = " << sq_root << endl;
    return;
}

int main() {
	int num = 5;
    sq_root(num);

    sq_root_binary(num, 0, num/2);
	return 0;
}

