#include <iostream>
#include <vector>

using namespace std;

/**
 * Check if word can be fit vertically in board
 */
vector<string> checkVertical(int row, int col, vector<string> board, string curr_word) {

    for(int i = 0; i < curr_word.length(); i++) {
        if((board[row + i][col] == '-') || (board[row + i][col] == curr_word[i])) {
            board[row + i][col] = curr_word[i];
        } else {
            // this shows that word cannot be placed horizontally
            board[0][0] = '@';
            return board;
        }
    }
 
    return board;
}

/**
 * Check if word can be fit horizontally in board
 *
 * row: index of row
 * col: index of col
 *
 */
vector<string> checkHorizontal(int row, int col, vector<string> board, string curr_word) {

    for(int i = 0; i < curr_word.length(); i++) {
        if((board[row][col + i] == '-') || (board[row][col + i] == curr_word[i])) {
            board[row][col + i] = curr_word[i];
        } else {
            // this shows that word cannot be placed horizontally
            board[0][0] = '@';
            return board;
        }
    }
 
    return board;
}

void printBoard(vector<string> board) {

    for(int i = 0; i < board.size(); i++) {
        cout << board[i] << endl;
    }
    cout << endl;
}

/**
 * Recursively check for each word in the vertical position and in the horizontal position
 * Then fill the word in the matrix that can be the best fit in the corresponding position of the grid
 */
void solveCrossword(vector<string> board, vector<string> words, int word_index, int total_rows, int total_cols) {

    // Base case: all words have been filled
    if(word_index == words.size()) {
        printBoard(board);
        return;
    }

    string curr_word = words[word_index];

    // loop to check the words that can align vertically
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < total_cols; j++) {
            vector<string> temp = checkVertical(i, j, board, curr_word);

            if(!temp.empty()) {
                if((temp[0].length() > 0) && (temp[0][0] != '@')) {
                    solveCrossword(temp, words, word_index + 1, total_rows, total_cols);
                }
            }
        }
    }

    // loop to check the words that can align horizontally
    for(int i = 0; i < total_rows; i++) {
        for(int j = 0; j < total_cols; j++) {
            vector<string> temp = checkHorizontal(i, j, board, curr_word);

            if(!temp.empty()) {
                if((temp[0].length() > 0) && (temp[0][0] != '@')) {
                    solveCrossword(temp, words, word_index + 1, total_rows, total_cols);
                }
            }
        }
    }
}

int main() {

    vector<string> words;
    words.push_back("CHEMISTRY");
    words.push_back("PHYSICS");
    words.push_back("HISTORY");
    words.push_back("CIVICS");
    words.push_back("GEOGRAPHY");
    words.push_back("MATH");

    // + indicated cannot be altered
    // - indicated can be replaced by a char
    vector<string> board;
    board.push_back("+++++++++-");
    board.push_back("-++++++++-"),
    board.push_back("-------++-"),
    board.push_back("-++++++++-"),
    board.push_back("-++++++++-"),
    board.push_back("-++++-----"),
    board.push_back("------+++-"),
    board.push_back("-++++++++-"),
    board.push_back("+---------"),
    board.push_back("++++++++++");

    // dimensions of board
    int row = 10;
    int col = 10;

    // index of word being checked from words
    int word_index = 0;

    solveCrossword(board, words, word_index, row, col);

    return 0;
}

