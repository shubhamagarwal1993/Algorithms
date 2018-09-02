// Print all possible partitions of a string into dictionary word

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string wordInDict(string str) {
    if(str == "abpcple") {
        cout << "inside apple check" << endl;
    }
    string dict[] = {"ale", "apple", "monkey", "plea"};
    int dict_size = sizeof(dict)/sizeof(*dict);

    for(int i = 0; i < dict_size; i++) {
        string dict_word = dict[i];

        if(str.length() < dict_word.length()) {
            return "";
        }
        cout << str << " " << dict_word << endl;

        unordered_map<int, int> count_map;

        for(int j = 0; j < dict_word.length(); j++) {
            count_map[int(dict_word[j])]++;
        }

        if(str == "abpcple") {
            for(auto it = count_map.begin(); it != count_map.end(); ++it) {
                cout << it->first << " -> " << it->second << endl;
            }
        }

        for(int j = 0; j < str.length(); j++) {
            if(count_map[int(str[j])] == 1) {
                count_map.erase(int(str[j]));
            } else if(count_map[int(str[j])] > 1) {
                count_map[int(str[j])]--;
            }
            if(count_map.empty()) {
                // substring matches
                return dict_word;
            }
        }
    }

    return "";
}

void findLongestSubstring(string str, int str_size, string longest_substr) {

    for(int i = 1; i <= str_size; i++) {
        string temp = str.substr(0, i);
        string str_matched = wordInDict(temp);
        if(str_matched.length() > 0) {

            if(str_matched.length() > longest_substr.length()) {
                longest_substr = str_matched;
            }

            cout << ":: " << str_matched << endl;
            // end of loop
            if(i == str_size) {
                cout << "****" << longest_substr << endl;
                return;
            }

            findLongestSubstring(str.substr(i), str_size - i, longest_substr);
        }
    }
}

int main() {
    string str = "abpcplea";
    int str_size = str.length();
    string longest_substr = "";
    findLongestSubstring(str, str_size, longest_substr);

    return 0;
}

