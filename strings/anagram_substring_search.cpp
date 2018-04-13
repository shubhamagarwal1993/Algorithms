#include<iostream>

#define ASCII_MAX 256
using namespace std;

bool compareArrays(char arr1[], char arr2[]) {
    for (int i = 0; i < ASCII_MAX; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void searchPattern(char input[], int input_size, char pat[], int pattern_size) {

    // pattern_arr: Store count of all characters of pattern
    // input_arr  : Store count of current window of text
    char pattern_count_arr[ASCII_MAX] = {0};
    char window_count_arr[ASCII_MAX] = {0};

    for (int i = 0; i < pattern_size; i++) {
        (pattern_count_arr[pat[i]])++;
        (window_count_arr[input[i]])++;
    }

    // Traverse through remaining characters of pattern
    for (int i = pattern_size; i < input_size; i++) {
        if (compareArrays(pattern_count_arr, window_count_arr))
            cout << "Found at Index " << (i - pattern_size) << endl;

        // Add current character to current window
        (window_count_arr[input[i]])++;

        // Remove the first character of previous window
        window_count_arr[input[i-pattern_size]]--;
    }

    // Check for the last window in text
    if (compareArrays(pattern_count_arr, window_count_arr))
        cout << "Found at Index " << (input_size - pattern_size) << endl;
}

int main() {
    char input[] = "BACDGABCDA";
    int input_size = strlen(input);
    char pattern[] = "ABCD";
    int pattern_size = strlen(pattern);
    searchPattern(input, input_size, pattern, pattern_size);
    return 0;
}

