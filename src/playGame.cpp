#include "playGame.hpp"
#include "displayBoard.hpp"
#include "checkWin.hpp"
#include <iostream>

using namespace std;

void playGame() {
    char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    int move;
    char currentPlayer = 'X';

    for (int turn = 0; turn < 9; ++turn) {
        displayBoard(board);
        cout << "Гравець " << currentPlayer << ", введіть номер клітинки (1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Невірний хід. Спробуйте ще раз.\n";
            --turn;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Гравець " << currentPlayer << " переміг УРААА!\n";
            return;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    displayBoard(board);
    cout << "Нічия!\n";
}