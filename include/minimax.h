#pragma once
/**
 * Biblioteca do algoritmo Minimax para o jogo da velha
 * 
 * Esta biblioteca implementa o algoritmo Minimax para criar uma IA
 * imbatível no jogo da velha. O algoritmo avalia todas as possíveis
 * jogadas futuras para escolher a melhor jogada.
 */

/**
 * Estrutura para representar uma jogada
 */
struct Move {
    int row;    
    int col;    
    int score;  
    
    /**
     * Construtor padrão
     */
    Move() : row(-1), col(-1), score(0) {}
    
    /**
     * Construtor com parâmetros
     * @param r Linha
     * @param c Coluna
     * @param s Pontuação
     */
    Move(int r, int c, int s) : row(r), col(c), score(s) {}
};

/**
 * Implementa o algoritmo Minimax recursivo
 * 
 * Este algoritmo avalia todas as possíveis jogadas futuras e retorna
 * a pontuação da melhor jogada possível para o jogador atual.
 * 
 * @param isMaximizing true se é a vez do BOT (maximizando), false se é a vez do PLAYER (minimizando)
 * @param depth Profundidade atual da recursão (para otimização)
 * @return Pontuação da melhor jogada possível
 */
int minimax(bool isMaximizing, int depth = 0);


Move getBestMove();
void makeBotMove();
int evaluateBoard();

