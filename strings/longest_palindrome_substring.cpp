#include <iostream>

using namespace std;

// Time complexity: O(n^2), Space complexity: O(n^2)
void printLongestPalindromeWithExtraSpace(char str[], int str_length) {

    bool table[str_length][str_length];

    int longest_palindrome_length = 1;

    // All substrings of length 1 are palindromes
    for(int i = 0; i < str_length; i++) {
        table[i][i] = true;
    }

    int start_index = 0;

    // check for sub strings of length 2
    for(int i = 0; i < str_length - 1; i++) {
        if(str[i] == str[i+1]) {
            table[i][i+1] = true;
            start_index = i;
            longest_palindrome_length = 2;
        }
    }

    // check for substrings greater than 1
    // k is length of substring
    for(int k = 3; k <= str_length; k++) {
        // fix the starting index
        for(int i = 0; i < str_length - k + 1; i++) {
            // get ending index of substring from starting index i and length k
            int j = i + k - 1;

            // check for substring from i to j
            if(table[i+1][j-1] && str[i] == str[j]) {
                table[i][j] = true;

                if(k > longest_palindrome_length) {
                    start_index = i;
                    longest_palindrome_length = k;
                }
            }
        }
    }

    cout << "Longest substring palindrome is ";
    for(int i = start_index; i < start_index + longest_palindrome_length; i++) {
        cout << str[i];
    }
    cout << " with length " << longest_palindrome_length << endl;

    return;
}

// Time complexity: O(n^2), Space complexity: O(1)
// Step to generate odd length palindrome:
//   Fix a centre and expand in both directions for longer palindromes
// Step to generate even length palindrome:
//   Fix two centre ( low and high ) and expand in both directions for longer palindromes
void printLongestPalindromeWithoutExtraSpace(char str[], int str_length) {

    int longest_palindrome_length = 1;

    int start_index = 0;
    int low = 0;
    int high = 0;

    // One by one consider every character as center point of even and odd length palindromes
    for(int i = 1; i < str_length; i++) {
        // even length palindrome with center points i-1 and i
        low = i - 1;
        high = i;
        while((low >= 0) && (high < str_length) && (str[low] == str[high])) {
            if(high - low + 1 > longest_palindrome_length) {
                longest_palindrome_length = high - low + 1;
                start_index = low;
            }
            low--;
            high++;
        }

        // odd length palindrome with centre point i
        low = i - 1;
        high = i + 1;
        while((low >= 0) && (high < str_length) && (str[low] == str[high])) {
            if(high - low + 1 > longest_palindrome_length) {
                longest_palindrome_length = high - low + 1;
                start_index = low;
            }
            low--;
            high++;
        }
    }

    cout << "Longest substring palindrome is ";
    for(int i = start_index; i < start_index + longest_palindrome_length; i++) {
        cout << str[i];
    }
    cout << " with length " << longest_palindrome_length << endl;

}

int main() {

    char str[] = "forgeeksskeegfor";
    int str_length = sizeof(str)/sizeof(str[0]);

    printLongestPalindromeWithExtraSpace(str, str_length);
    printLongestPalindromeWithoutExtraSpace(str, str_length);

    return 0;
}
