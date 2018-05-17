#include <iostream>
#include <unordered_map>

#define ASCII_MAX 256

using namespace std;

void computeLPSArray(string pattern, int pattern_size, int lpsArray[]) {
    
}

int KMPSearch(string input, int input_size, string pattern, int pattern_size) {

    // Create an LPS array - Longest Proper Prefix which is also Suffix
    // E.g. input is "ABC", proper prefixes are "A", and "AB"; but not "ABC"
    int lpsArray[pattern_size];
    computeLPSArray(pattern, pattern_size, lpsArray);

    int input_index = 0;
    int pattern_index = 0;

    return 0;
}

void searchNaive(string input, int input_size, string pattern, int pattern_size) {

    int pattern_index = 0;

    for(int i = 0; i < input_size; i++) {

        // check for last char of pattern
        if(pattern_index == pattern_size - 1) {
            if(pattern[pattern_index] == input[i]) {
                cout << "Pattern found at index: " << i - (pattern_size - 1) << endl;
            }
            pattern_index = 0;
        } else if(pattern[pattern_index] == input[i]) {
            pattern_index++;
        } else {
            pattern_index = 0;
        }

    }
}

int main() {

    string input = "DFGBTHBACDGABCDAJFDSFSDKFNABCDNSDIFABCD";
    int input_size = input.size();
    string pattern = "ABCD";
    int pattern_size = pattern.size();

    searchNaive(input, input_size, pattern, pattern_size);
    int temp = KMPSearch(input, input_size, pattern, pattern_size);
    return 0;
}

