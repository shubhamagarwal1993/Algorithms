#include <iostream>
#include <unordered_map>

using namespace std;

void printOrderedString(string input) {

    unordered_map<int, int> string_map;
    int charCount[26] = {0};

    for(int i = 0; i < input.size(); i++) {
        string_map[input[i]-'a']++;
        charCount[input[i] - 'a']++;
    }

    for(auto it = string_map.begin(); it != string_map.end(); it++) {
        cout << (char)(it->first+'a') << " " << it->second << endl;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < charCount[i]; j++) {
            cout << (char)(i + 'a') << " ";
        }
    }
    cout << endl;
}

int main() {

    string input = "zxmkjsdnfwoefso";
    printOrderedString(input);
    return 0;
}

