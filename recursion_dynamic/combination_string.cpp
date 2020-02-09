#include <iostream>

using namespace std;

//-----------------------------------------------------
void permutation_inorder(string prefix, string str) {
    if (str.length() == 0) {
        cout << prefix <<  endl;
        return;
    }

    for(int i = 0; i < str.length(); i++) {
        string prefix_new = prefix + str[i];
        string str_new = str.substr(0, i) + str.substr(i+1);
        //cout << "temp " << temp << "  \ttemp1 " << temp1 << "  \t " << i << endl;
        permutation_inorder(prefix_new, str_new);
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
void permutation_duplicates(string str, int index) {

    // reached end of string
    if(index == str.length()) {
        cout << str << endl;
        return;
    }

    permutation_duplicates(str, index + 1);

    for(int i = index + 1; i < str.length(); i++) {
        if(str[index] == str[i]) {
            continue;
        }
        swap(index, i, str);
        permutation_duplicates(str, index + 1);
    }
}

//-----------------------------------------------------
int main() {
    permutation_inorder("", "abc");
    cout << "--------------------------" << endl;
    permutation_out_of_order("abc", 0);
    cout << "--------------------------" << endl;
    permutation_duplicates("aabc", 0);
    cout << "--------------------------" << endl;
    // Write this function - should avoid duplicates, can avoid swapping with self, and use above methods
    //permutation_duplicates_inorder("aabc", 0);
    return 0;
}

