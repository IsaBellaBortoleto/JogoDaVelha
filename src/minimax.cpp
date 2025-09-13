#include "../include/minimax.h"
#include "../include/board.h"
#include "../include/ui.h"
#include <limits>
#include <algorithm>
using namespace std;

int evaluateBoard() {
    string result = checkWinner();
    if (result == string(1, BOT)) return 10;
    if (result == string(1, PLAYER)) return -10;
    if (result == "tie") return 0;
    return 0; // Jogo em andamento
}

int minimax(bool isMaximizing, int depth) {
    string result = checkWinner();
    
    // Caso base: jogo terminou
    if (result != "none") {
        if (result == string(1, BOT)) return 10 - depth;
        if (result == string(1, PLAYER)) return depth - 10;
        if (result == "tie") return 0;
    }

    if (isMaximizing) {
        // Vez do BOT (maximizar a pontuação)
        int bestScore = numeric_limits<int>::min();
        
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (isPositionEmpty(i, j)) {
                    makeMove(i, j, BOT);
                    int score = minimax(false, depth + 1);
                    undoMove(i, j);
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        // Vez do PLAYER (minimizar a pontuação)
        int bestScore = numeric_limits<int>::max();
        
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (isPositionEmpty(i, j)) {
                    makeMove(i, j, PLAYER);
                    int score = minimax(true, depth + 1);
                    undoMove(i, j);
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

Move getBestMove() {
    Move bestMove;
    bestMove.score = numeric_limits<int>::min();

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (isPositionEmpty(i, j)) {
                makeMove(i, j, BOT);
                int score = minimax(false, 0);
                undoMove(i, j);
                
                if (score > bestMove.score) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestMove.score = score;
                }
            }
        }
    }
    
    return bestMove;
}

void makeBotMove() {
    Move bestMove = getBestMove();
    
    if (bestMove.row != -1 && bestMove.col != -1) {
        makeMove(bestMove.row, bestMove.col, BOT);
        displayBotMove(bestMove.row + 1, bestMove.col + 1); // +1 para exibição baseada em 1
    }
}