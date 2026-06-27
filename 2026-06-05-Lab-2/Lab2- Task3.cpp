#include <iostream>
using namespace std;

// All possible winning triplets (indexes into board[0..8])
int win[8][3] = {
    {0,1,2},  // rows
    {3,4,5},  // rows
    {6,7,8},  // rows
    {0,3,6},  // columns
    {1,4,7},  // columns
    {2,5,8},  // columns
    {0,4,8},// diagonals
     {2,4,6} // diagonals
};

// Returns true if character 'c' (X or O) has a winning line
bool isWin(char *board, char c) {
    for (int i = 0; i < 8; i++) {
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c)
            return true;
    }
    return false;   // no winning line found
}

// Returns true if the given board represents a valid Tic‑Tac‑Toe position
bool isValid(char board[9]) {
    // Count X and O
    int countX = 0, countO = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 'X') countX++;
        if (board[i] == 'O') countO++;
    }

    // Valid counts: X == O or X == O + 1
    if (countX == countO || countX == countO + 1) {
        // If O wins, X must NOT also win, and counts must be equal (O moved last)
        if (isWin(board, 'O')) {
            if (isWin(board, 'X'))
                return false;          // both cannot win
            return (countX == countO);
        }

        // If X wins, counts must be X == O + 1 (X moved last)
        if (isWin(board, 'X') && countX != countO + 1)
            return false;

        // No winner (or X wins with correct counts) = valid
        return true;
    }
    return false;   // count difference invalid
}

int main() {
    char board[] = {
        'X', 'X', 'O',
        'O', 'O', 'X',
        'X', 'O', 'X'
    };

    cout << (isValid(board) ? "Given board is valid" : "Given board is not valid");
    return 0;
}