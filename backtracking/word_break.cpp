// Print all possible partitions of a string into dictionary word

#include <iostream>
#include <vector>

using namespace std;

bool wordInDict(string str) {
    string dict[] = {"mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "love", "ice", "cream"};
    int dict_size = sizeof(dict)/sizeof(*dict);

    for(int i = 0; i < dict_size; i++) {
        if(dict[i] == str) {
            return true;
        }
    }
    return false;
}

void wordBreak(string str, int str_size, string answer) {

    for(int i = 1; i <= str_size; i++) {
        string temp = str.substr(0, i);
        if(wordInDict(temp)) {
            // append valid word
            if(answer.empty()) {
                answer = temp;
            } else {
                answer = answer + " " + temp;
            }

            // end of loop
            if(i == str_size) {
                cout << answer << endl;
                return;
            }

            wordBreak(str.substr(i), str_size - i, answer);
        }
    }
}

bool wordBreakTest(string str, int str_size, vector<string> vec, int index) {
    if(index >= str_size - 1) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << endl;
        }
        return true;
    }

    for(int i = 0; i < str_size; i++) {
        string temp = str.substr(0, i);

        if(wordInDict(temp)) {
            vec.push_back(temp);
            bool foundWord = wordBreakTest(str.substr(i), str_size - i, vec, index+1);
            if(foundWord) {
                vec.clear();
            } else {
                vec.pop_back();
            }
        }
    }
    return false;
}

int main() {
    string str = "iloveicecreamandmango";
    int str_size = str.length();
//    wordBreak(str, str_size, "");

    vector<string> vec;
    wordBreakTest(str, str_size, vec, 0);
    return 0;
}

