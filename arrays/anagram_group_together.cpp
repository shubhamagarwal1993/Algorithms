// array of words, print all anagrams together
// Example: given array {“cat”, “dog”, “tac”, “god”, “act”}, output “cat tac act dog god”
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Running time is O(NM)
// Space complexity is O(N)
void printAnagrams(string arr[], int arr_size) {

    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    unordered_map<int, vector<string>> anagrams;

    for(int i = 0; i < arr_size; i++) {
        int key = 1;
        for(int j = 0; j < arr_size; j++) {
            key *= char(prime[arr[i][j]]);
        }

        vector<string> words;
        auto search = anagrams.find(key);
        if(search != anagrams.end()) {
            words = anagrams[key];
        }
        words.push_back(arr[i]);

        anagrams[key] = words;
    }

    cout << "Anagrams are: " << endl;
    for(auto it = anagrams.begin(); it != anagrams.end(); ++it) {
        vector<string> temp = it->second;
        for(int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {

    string arr[] = {"eat", "pots", "onset", "stone", "rail", "risen", "caret", "resin", "react", "siren", "sitar", "stair", "liar", "stop", "trace", "notes", "tea", "lair" };
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printAnagrams(arr, arr_size);
    return 0;
}
