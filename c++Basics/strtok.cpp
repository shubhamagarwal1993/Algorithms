#include <iostream>

using namespace std;

int main() {

    char str[] ="- This, a sample string.";
    char* pch;
    cout << "Splitting string " << str << " into tokens" << endl;
    pch = strtok (str," ,.-");
    while(pch != NULL) {
        cout << pch << endl;
        pch = strtok (NULL, " ,.-");
    }
    return 0;
}
