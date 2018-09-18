#include <iostream>
#include <vector>

using namespace std;

#define N 3

class GameBoard {
    private:
        int* board;
        bool game_completed;

        // turn true is for p0, false for p1
        bool turn;

    public:
        GameBoard() {
            this->board = new int[N*N];

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    this->board[N*i + j] = -1;
                }
            }

            this->game_completed = false;
            this->turn = false;
        }

        bool gameCompleted() {
            return this->game_completed;
        }

        bool currTurn() {
            return this->turn;
        }

        void nextTurn() {
            this->turn = this->turn ? false : true;
        }

        void printGameBoard() {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(this->board[N*i + j] != -1) {
                        cout << " " << this->board[N*i + j] << " ";
                    } else {
                        cout << this->board[N*i + j] << " ";
                    }
                }
                cout << endl;
            }
        }

        /**
         */
        bool makeMove(int x, int y, int player_no) {
            int curr_val = this->board[N*x + y];
            if(curr_val != -1) {
                return false;
            }
            if(player_no == 0) {
                this->board[N*x + y] = 0;
            } else {
                this->board[N*x + y] = 1;
            }

            // chec if player won
            if(checkWin(x, y)) {
                cout << "Game over" << endl;
                this->game_completed = true;
            }
            return true;
        }

        bool validCell(int x, int y) {
            if(x < 0 || x >= N) {
                return false;
            }
            if(y < 0 || y >= N) {
                return false;
            }
            return true;
        }

//        bool horizontalVerticalWin(int x, int y, int player_no) {
//            bool verticalWin = false;
//            // vertical win
//            if((validCell(x+1, y) && validCell(x-1, y))
//            &&(this->vec[(x+1)*N + y] == player_no) &&(this->vec[(x-1)*N + y] == player_no) && (this->vec[x*N + y] == player_no)) {
//                verticalWin = true;
//            }
//
//            bool horizontalWin = false;
//            // vertical win
//            if((validCell(x, y+1) && validCell(x, y-1))
//            &&(this->vec[(y+1)*N + y] == player_no) &&(this->vec[(y-1)*N + y] == player_no) && (this->vec[y*N + y] == player_no)) {
//                verticalWin = true;
//            }
//            return false;
//        }

        bool checkWin(int x, int y) {

            // Check the rows
            for(int i = 0; i < 3; i++) {
                if((board[N*i + 0] == board[N*i + 1]) && (board[N*i + 1] == board[N*i + 2])) {
                    return true;
                }
            }

            // Check the columns
            for(int i = 0; i < 3; i++) {
                if((board[N*0 + i] == turn) && (board[N*0 + i] == board[N*1 + i]) && (board[N*1 + i] == board[N*2 + i])) {
                    return true;
                }
            }

            // Check top left diagonal
            if((board[N*0 + 0] == turn) && (board[N*0 + 0] == board[N*1 + 1]) && (board[N*1 + 1] == board[N*2 + 2])) {
                return true;
            }

            // Check top right diagonal
            if((board[N*2 + 0] == turn) && (board[N*2 + 0] == board[N*1 + 1]) && (board[N*1 + 1] == board[N*0 + 2])) {
                return true;
            }

            return false;
        }
};

class Player : public GameBoard {
    private:

    public:
        Player() {
        
        }

        bool makeMove(int x, int y, GameBoard gb, int player_no) {
            return gb.makeMove(x, y, player_no);
        }
};

int main() {

    GameBoard gb;

    int x;
    int y;

    Player p0;
    Player p1;

    while(!gb.gameCompleted()) {
        cout << "Game completed " << gb.gameCompleted() << endl;

        cout << "Player " << gb.currTurn() << " move" << endl;
        // validate user input
        cin >> x;
        cin >> y;

        if(gb.currTurn()) {
            cout << "inside player 0 case" << endl;
            // make move
            p0.makeMove(x, y, gb, 0);
        } else {
            p1.makeMove(x, y, gb, 1);
        }
        gb.nextTurn();

        // print current state of game board
        gb.printGameBoard();
    }

    return 0;
}
