//to check whether a given tic tac toe board is valid or not
#include <iostream>
using namespace std;

int win[8][3] ={{0, 1, 2}, // Check first row
                {3, 4, 5}, // Check second row
                {6, 7, 8}, // Check third row
                {0, 3, 6}, // Check first column
                {1, 4, 7}, // Check second column
                {2, 5, 8}, // Check third column
                {0, 4, 8}, // Check first diagonal
                {2, 4, 6}  // Check second diagonal
               };

bool checkWin(char *board, char c) {
    for (int i=0; i<8; i++) //check all possible winning combinations
        if (board[win[i][0]] == c && board[win[i][1]] == c && board[win[i][2]] == c )
            return true;
    return false;
}

bool checkTicTacToe(char board[]) {
    int xCount=0, oCount=0;
    for (int i=0; i<9; i++) {
        if (board[i]=='X')
            xCount++;
        if (board[i]=='O')
            oCount++;
    }
    if (xCount==oCount || xCount==oCount+1) { //board can be valid only if either xCount and oCount is same or xCount is one more than oCount
        if (checkWin(board, 'O')) { //if 'O' is winner
            if (checkWin(board, 'X')) //if 'X' is also winner
                 return false;
            else //else return true if xCount and yCount are same
                return (xCount == oCount);
        }
        if (checkWin(board, 'X') && xCount != oCount + 1) //count of X must be greater if 'X' wins
            return false;
        return true; //'X' wins or no winner
    }
    return false; //default
}

int main() {
    char board[] = {'X', 'X', 'O',
                    'O', 'O', 'X',
                    'X', 'O', 'X'};
    cout<<"Given board is "<<(checkTicTacToe(board)?"VALID":"NOT VALID")<<endl;
    return 0;
}
