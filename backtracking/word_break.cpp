// Print all possible partitions of a string into dictionary word

#include <iostream>

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

int main() {
    string str = "iloveicecreamandmango";
    int str_size = str.size();
    wordBreak(str, str_size, "");
    return 0;
}

