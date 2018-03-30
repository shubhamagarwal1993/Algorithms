#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    //declaring unordered map
    unordered_map<int, int> mymap;

    //insert a key value pair
    mymap.insert( {{66,8},{5,0}} );
    mymap.insert({9,1});
    mymap[6] = 76;

    //map size
    cout << "map size: " << mymap.size() << endl;

    // find a key
    auto search = mymap.find(6);
    if(search != mymap.end())
        cout << "Found " << search->first << " -> " << search->second << endl;
    else
        std::cout << "Not found" << endl;

    // erasing by key
    mymap.erase (6);

    //checks if map is empty
    if (mymap.empty())
        cout << "map is empty" << endl;
    else
        cout << "map is not empty" << endl;

    //print out all the key value pair
    cout << "===========" << endl;
    for (auto it = mymap.begin(); it != mymap.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << "===========" << endl;

    //clear the map. call the destructor and make size 0
    mymap.clear();

    return 0;
}

