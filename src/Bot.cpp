#include "Bot.h"
#include <iostream>
#include <climits>

// Definições de cores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define ORANGE  "\033[38;5;208m"
#define BOLD    "\033[1m"


Bot::Bot(string nome, char simbolo) : Entity(nome, simbolo) {
}


Bot::~Bot() {
}



/**
 * Avalia o estado atual do tabuleiro
 */
int Bot::evaluateBoard(Board& board) {
    string result = board.checkWinner();
    
    if (result == string(1, getSimbolo())) {
        return 10; // Bot ganhou
    } else if (result != "none" && result != "tie") {
        return -10; // Humano ganhou
    }
    return 0; // Empate ou jogo continua
}

/**
 * Implementa o algoritmo minimax
 */
int Bot::minimax(Board& board, int depth, bool isMaximizing) {
    int score = evaluateBoard(board);
    
    // Se o jogo terminou, retorna a pontuação
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (board.countEmptySpots() == 0) return 0;
    
    if (isMaximizing) {
        int bestScore = INT_MIN;
        
        // Tentar todas as jogadas possíveis para o bot
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.isPositionEmpty(i, j)) {
                    board.makeMove(i, j, getSimbolo());
                    int currentScore = minimax(board, depth + 1, false);
                    board.undoMove(i, j);
                    bestScore = std::max(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        
        // Tentar todas as jogadas possíveis para o humano
        char humanSymbol = (getSimbolo() == 'X') ? 'O' : 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.isPositionEmpty(i, j)) {
                    board.makeMove(i, j, humanSymbol);
                    int currentScore = minimax(board, depth + 1, true);
                    board.undoMove(i, j);
                    bestScore = std::min(bestScore, currentScore);
                }
            }
        }
        return bestScore;
    }
}

/**
 * Faz a melhor jogada possível usando minimax
 */
bool Bot::fazerJogada(Board& board) {
    cout << BOLD << MAGENTA << getNome() << " esta pensando..." << RESET << endl;
    
    int bestScore = INT_MIN;
    int bestRow = -1;
    int bestCol = -1;
    
    // Avaliar todas as jogadas possíveis
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.isPositionEmpty(i, j)) {
                board.makeMove(i, j, getSimbolo());
                int score = minimax(board, 0, false);
                board.undoMove(i, j);
                
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    
    // Fazer a melhor jogada encontrada
    if (bestRow != -1 && bestCol != -1) {
        board.makeMove(bestRow, bestCol, getSimbolo());
        setPosition(bestRow, bestCol);
        
        // Mostrar a jogada do bot (convertendo para coordenadas 1-3)
        cout << BOLD << ORANGE << getNome() << " jogou na posicao (" 
             << (bestRow + 1) << ", " << (bestCol + 1) << ")" << RESET << endl;
        return true;
    }
    
    return false;
}