#include "../include/board.h"
using namespace std;
// Definição das constantes
const char BOT = 'X';
const char PLAYER = 'O';
const int BOARD_SIZE = 3;

// Definição do tabuleiro global
char board[3][3];

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

bool equals3(char a, char b, char c) {
    return (a == b && b == c && a != ' ');
}

string checkWinner() {
    // Checagem horizontal
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (equals3(board[i][0], board[i][1], board[i][2])) {
            return string(1, board[i][0]);
        }
    }
    
    // Checagem vertical
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (equals3(board[0][i], board[1][i], board[2][i])) {
            return string(1, board[0][i]);
        }
    }
    
    // Checagem diagonal principal
    if (equals3(board[0][0], board[1][1], board[2][2])) {
        return string(1, board[0][0]);
    }
    
    // Checagem diagonal secundária
    if (equals3(board[2][0], board[1][1], board[0][2])) {
        return string(1, board[2][0]);
    }

    // Verifica empate
    if (countEmptySpots() == 0) {
        return "tie";
    }

    return "none"; // Jogo continua
}

int countEmptySpots() {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                count++;
            }
        }
    }
    return count;
}

bool isPositionEmpty(int row, int col) {
    if (!isValidPosition(row, col)) {
        return false;
    }
    return board[row][col] == ' ';
}

bool isValidPosition(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

bool makeMove(int row, int col, char player) {
    if (!isValidPosition(row, col) || !isPositionEmpty(row, col)) {
        return false;
    }
    board[row][col] = player;
    return true;
}

void undoMove(int row, int col) {
    if (isValidPosition(row, col)) {
        board[row][col] = ' ';
    }
}