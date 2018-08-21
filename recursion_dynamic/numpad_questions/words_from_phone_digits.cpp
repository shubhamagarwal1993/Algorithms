#include <iostream>
#include <algorithm>

using namespace std;

// 2d array to store phone numberpad digits to alphabets
const string hashTable[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//                             0   1    2      3      4      5      6       7      8       9

void printWordsUtil(int num_array[], int num_array_size, int curr_digit, char result[]) {

    // Base case, if current output word is prepared
    if(curr_digit == num_array_size) {
        for(int i = 0; i < num_array_size; i++) {
            cout << result[i];
        }
        cout << endl;
        return;
    }

    // Try all possible chars for current digit in num_array[] and recur for remaining digits
    for(int i = 0; i < (hashTable[num_array[curr_digit]]).length(); i++) {
        // add char to array and go to next num in array
        result[curr_digit] = hashTable[num_array[curr_digit]][i];
        printWordsUtil(num_array, num_array_size, curr_digit + 1, result);

        if(num_array[curr_digit] == 0 || num_array[curr_digit] == 1) {
            return;
        }
    }
}

void printWords(int num_array[], int num_array_size) {
    char result[num_array_size];
    int starting_index = 0;
    printWordsUtil(num_array, num_array_size, starting_index, result);
}

int main() {
    int num_array[] = {2, 7};//, 3, 4};
    int num_array_size = sizeof(num_array)/sizeof(num_array[0]);
    printWords(num_array, num_array_size);
    return 0;
}
