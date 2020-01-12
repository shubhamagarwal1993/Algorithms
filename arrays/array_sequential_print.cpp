// Find location of rectangle in 2D array and its dimensions

#include <iostream>
#include <vector>

using namespace std;

void print_sequential(vector<vector<int> > vec) {

    vector<int> vec_idx;
    for(int i = 0; i < vec.size(); i++) {
        vec_idx.push_back(0);
    }

    bool done = false;
    while(!done) {
        done = true;
        for(int outer_idx = 0; outer_idx < vec.size(); outer_idx++) {
            if(vec_idx[outer_idx] < vec[outer_idx].size()) {
                cout << vec[outer_idx][vec_idx[outer_idx]] << " ";

                vec_idx[outer_idx] += 1;
                done = false;
            }
        }
    }
    cout << endl;

    return;
}

int main() {

    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4};
    vector<int> vec3 = {5, 6};

    vector<vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);

    print_sequential(vec);
    return 0;
}


