#include <iostream>

using namespace std;

//-----------------------------------------------------
void permutation_inorder(string prefix, string str) {
    int n = str.length();
    if (n == 0) {
        cout << "---" << prefix <<  "---" << endl << endl;
    } else {
        for (int i = 0; i < n; i++) {
            string temp = prefix + str[i];
            string temp1 = str.substr(0, i) + str.substr(i+1, n);
            cout << "temp " << temp << "  \ttemp1 " << temp1 << "  \t " << i << endl;
            permutation_inorder(prefix + str[i], str.substr(0, i) + str.substr(i+1, n));
        }
    }
    return;
}

//-----------------------------------------------------
void swap(int l, int r, string &str) {
    char temp = str[l];
    str[l] = str[r];
    str[r] = temp;
}

void permutation_out_of_order(string str, int index) {
    
    if(index == str.size()) {
        cout << str << endl;
    }

    for(int i = index; i < str.size(); i++) {
        swap(index, i, str);
        permutation_out_of_order(str, index+1);
        swap(index, i, str);
    }
}

//-----------------------------------------------------
int main() {
    permutation_inorder("", "abc");
    permutation_out_of_order("abc", 0);
    return 0;
}

