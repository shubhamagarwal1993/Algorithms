#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<vector<int> > myvec;

    for(int i = 0; i < 3; i++) {
        vector<int> temp;
        for(int j = 0; j < 5; j++) {
            temp.push_back(i);
        }
        myvec.push_back(temp);
    }

    for(int i = 0; i < myvec.size(); i++) {
        for(int j = 0; j < myvec[i].size(); j++) {
            cout << myvec[i][j];
        }
        cout << endl;
    }
}
