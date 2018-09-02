#include <iostream>
#include <unordered_map>

#define ASCII_MAX 256

using namespace std;

/*
 * lps[i] could also be defined as longest prefix which is also proper suffix
 * We need to use "proper" at one place to make sure that the whole substring is not considered
 *
 * Examples of lps[] construction:
 * For the pattern “AAAA”
 * lps[] is [0, 1, 2, 3]
 *
 * For the pattern “ABCDE”
 * lps[] is [0, 0, 0, 0, 0]
 *
 * For the pattern “AABAACAABAA”
 * lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
 *
 * For the pattern “AAACAAAAAC”
 * lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 
 *
 * For the pattern “AAABAAA”
 * lps[] is [0, 1, 2, 0, 1, 2, 3]
 *
 * Unlike Naive algorithm, where we slide the pattern by one and compare all characters
 * at each shift, we use a value from lps[] to decide the next characters to be matched
 * The idea is to not match a character that we know will anyway match
 */
void computeLPSArray(string pattern, int pattern_size, int lps[]) {

    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while(i < pattern_size) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else { // (pat[i] != pat[len])
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if(len != 0) {
                len = lps[len - 1];
                // We do not increment i here
            } else { // if (len == 0)
                lps[i] = 0;
                i++;
            }
        }
    }
}

/*
 * N - length of string
 * Time complexity: O(N)
 */
int KMPSearch(string input, int input_size, string pattern, int pattern_size) {

    // Create an LPS array - Longest Proper Prefix which is also Suffix
    // E.g. input is "ABC", proper prefixes are "A", and "AB"; but not "ABC"
    int lps[pattern_size];
    computeLPSArray(pattern, pattern_size, lps);

    int input_index = 0;
    int pattern_index = 0;

    while(input_index < input_size) {
        if(pattern[pattern_index] == input[input_index]) {
            input_index++;
            pattern_index++;
        }
 
        if(pattern_index == pattern_size) {
            cout << "Found pattern at index " << input_index - pattern_index << endl;
            pattern_index = lps[pattern_index - 1];
        } else if(input_index < input_size && pattern[pattern_index] != input[input_index]) {   // mismatch after j matches
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if(pattern_index != 0) {
                pattern_index = lps[pattern_index - 1];
            } else {
                input_index = input_index + 1;
            }
        }
    }

    return 0;
}

/*
 * M - length of pattern
 * N - length of string
 * Time complexity: O(M * (N-M+1))
 */
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

    string input = "ABABDABACDABABCABAB";
    //string input = "DFGBTHBACDGABCDAJFDSFSDKFNABCDNSDIFABCD";
    int input_size = input.size();
    string pattern = "ABABCABAB";
    int pattern_size = pattern.size();

    searchNaive(input, input_size, pattern, pattern_size);
    int temp = KMPSearch(input, input_size, pattern, pattern_size);
    return 0;
}

