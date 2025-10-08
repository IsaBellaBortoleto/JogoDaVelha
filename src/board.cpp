#include "../include/Board.h"
#include <iostream>
using namespace std;


Board::Board() {
    initBoard();
}


Board::~Board() {
}

/**
 * Inicializa o tabuleiro com espaços vazios
 */
void Board::initBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

/**
 * Método auxiliar privado para verificar se três posições são iguais
 */
bool Board::equals3(char a, char b, char c) const {
    return (a == b && b == c && a != EMPTY);
}

/**
 * Verifica o estado atual do jogo
 */
string Board::checkWinner() const {
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

/**
 * Conta quantas posições estão vazias no tabuleiro
 */
int Board::countEmptySpots() const {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                count++;
            }
        }
    }
    return count;
}

/**
 * Verifica se uma posição específica está vazia
 */
bool Board::isPositionEmpty(int row, int col) const {
    if (!isValidPosition(row, col)) {
        return false;
    }
    return board[row][col] == EMPTY;
}

/**
 * Verifica se as coordenadas são válidas
 */
bool Board::isValidPosition(int row, int col) const {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

/**
 * Faz uma jogada no tabuleiro
 */
bool Board::makeMove(int row, int col, char player) {
    if (!isValidPosition(row, col) || !isPositionEmpty(row, col)) {
        return false;
    }
    board[row][col] = player;
    return true;
}

/**
 * Desfaz uma jogada no tabuleiro
 */
void Board::undoMove(int row, int col) {
    if (isValidPosition(row, col)) {
        board[row][col] = EMPTY;
    }
}

/**
 * Retorna o símbolo em uma posição específica
 */
char Board::getPosition(int row, int col) const {
    if (!isValidPosition(row, col)) {
        return EMPTY;
    }
    return board[row][col];
}

/**
 * Imprime o tabuleiro formatado com coordenadas de 1 a 3
 */
void Board::printBoard() const {
    cout << "\n    1   2   3" << endl;
    cout << "  -------------" << endl;
    
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << (i + 1) << " | ";  // Mostrar linha como 1, 2, 3
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n  -------------" << endl;
    }
    cout << "\n";
}