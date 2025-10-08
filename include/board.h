#pragma once

#include <string>
using namespace std;

/**
 * Classe Board para gerenciamento orientado a objetos do tabuleiro
 * 
 * Esta classe encapsula o tabuleiro e suas operações, seguindo princípios
 * de orientação a objetos com dados privados e métodos públicos.
 */
class Board {
private:
    static const int BOARD_SIZE = 3;
    char board[BOARD_SIZE][BOARD_SIZE];
    
    static const char BOT = 'X';
    static const char PLAYER = 'O';
    static const char EMPTY = ' ';
 
    bool equals3(char a, char b, char c) const;

public:
    // Construtor e Destrutor
    Board();
    ~Board();
    
    // Métodos públicos (interface da classe)
    void initBoard();
    string checkWinner() const;
    int countEmptySpots() const;
    bool isPositionEmpty(int row, int col) const;
    bool isValidPosition(int row, int col) const;
    bool makeMove(int row, int col, char player);
    void undoMove(int row, int col);
    
    // Métodos para acesso controlado aos dados
    char getPosition(int row, int col) const;
    void printBoard() const;
    
    // Getters para constantes
    static char getBotSymbol() { return BOT; }
    static char getPlayerSymbol() { return PLAYER; }
    static char getEmptySymbol() { return EMPTY; }
    static int getBoardSize() { return BOARD_SIZE; }
};

