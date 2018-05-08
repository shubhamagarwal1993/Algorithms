#include <iostream>
#include <unordered_map>

#define ASCII_MAX 256

using namespace std;

bool compareArrays(char arr1[], char arr2[]) {
    for(int i = 0; i < ASCII_MAX; i++) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

bool compareMaps(unordered_map<char, int> map1, unordered_map<char, int> map2) {
    return map1 == map2;
}

// Have used a map and an array to show that both can be used to solve this
void searchPattern(char input[], int input_size, char pat[], int pattern_size) {

    // pattern_count_arr: Store count of all characters of pattern
    // input_count_arr  : Store count of current window of text
    unordered_map<char, int> pattern_count_map;
    unordered_map<char, int> window_count_map;

    char pattern_count_arr[ASCII_MAX] = {0};
    char window_count_arr[ASCII_MAX] = {0};

    for(int i = 0; i < pattern_size; i++) {
        (pattern_count_arr[pat[i]])++;
        (window_count_arr[input[i]])++;
        pattern_count_map[pat[i]]++;
        window_count_map[pat[i]]++;
    }

    for(auto it = window_count_map.begin(); it != pattern_count_map.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << endl;

    // Traverse through remaining characters of pattern
    for(int i = pattern_size; i < input_size; i++) {
        if(compareArrays(pattern_count_arr, window_count_arr))
            cout << "Arr Found at Index " << (i - pattern_size) << endl;

        if(compareMaps(pattern_count_map, window_count_map))
            cout << "Map Found at Index " << (i - pattern_size) << endl;

        // Add current character to current window
        (window_count_arr[input[i]])++;

        // find a key
        auto search = window_count_map.find(input[i]);
        if(search != window_count_map.end())
            window_count_map[input[i]]++;
        else
            window_count_map[input[i]] = 1;

        // Remove the first character of previous window
        window_count_arr[input[i-pattern_size]]--;

        search = window_count_map.find(input[i-pattern_size]);
        if(search != window_count_map.end()) {
            int count = window_count_map[input[i-pattern_size]];
            if(count == 1) {
                window_count_map.erase(input[i-pattern_size]);
            } else {
                window_count_map[input[i-pattern_size]] = count - 1;
            }
        }
    }

    // Check for the last window in text
    if(compareArrays(pattern_count_arr, window_count_arr))
        cout << "Arr Found at Index " << (input_size - pattern_size) << endl;
    if(compareMaps(pattern_count_map, window_count_map))
        cout << "Map Found at Index " << (input_size - pattern_size) << endl;
}

int main() {
    char input[] = "BACDGABCDA";
    int input_size = strlen(input);
    char pattern[] = "ABCD";
    int pattern_size = strlen(pattern);
    searchPattern(input, input_size, pattern, pattern_size);
    return 0;
}

