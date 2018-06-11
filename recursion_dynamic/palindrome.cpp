#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool palindrome(string temp, int l, int r, int size) {
    if(l >= r)
        return true;

    if(temp[l] != temp[r])
        return false;
    else
        return palindrome(temp, l+1, r-1, size);
}

int main() {
    string temp = "ppsddspp";
    cout << palindrome(temp, 0, temp.size() - 1, temp.size()) << endl;

    return 0;
}
