#ifndef MINIMAX_H
#define MINIMAX_H

/**
 * @brief Biblioteca do algoritmo Minimax para o jogo da velha
 * 
 * Esta biblioteca implementa o algoritmo Minimax para criar uma IA
 * imbatível no jogo da velha. O algoritmo avalia todas as possíveis
 * jogadas futuras para escolher a melhor jogada.
 */

/**
 * @brief Estrutura para representar uma jogada
 */
struct Move {
    int row;    ///< Linha da jogada (0-2)
    int col;    ///< Coluna da jogada (0-2)
    int score;  ///< Pontuação da jogada avaliada pelo Minimax
    
    /**
     * @brief Construtor padrão
     */
    Move() : row(-1), col(-1), score(0) {}
    
    /**
     * @brief Construtor com parâmetros
     * @param r Linha
     * @param c Coluna
     * @param s Pontuação
     */
    Move(int r, int c, int s) : row(r), col(c), score(s) {}
};

/**
 * @brief Implementa o algoritmo Minimax recursivo
 * 
 * Este algoritmo avalia todas as possíveis jogadas futuras e retorna
 * a pontuação da melhor jogada possível para o jogador atual.
 * 
 * @param isMaximizing true se é a vez do BOT (maximizando), false se é a vez do PLAYER (minimizando)
 * @param depth Profundidade atual da recursão (para otimização)
 * @return Pontuação da melhor jogada possível
 */
int minimax(bool isMaximizing, int depth = 0);

/**
 * @brief Encontra a melhor jogada possível para o BOT
 * 
 * Usa o algoritmo Minimax para avaliar todas as jogadas possíveis
 * e retorna a jogada com a melhor pontuação.
 * 
 * @return Estrutura Move com a melhor jogada (linha, coluna e pontuação)
 */
Move getBestMove();

/**
 * @brief Executa a melhor jogada para o BOT
 * 
 * Calcula a melhor jogada usando getBestMove() e a executa no tabuleiro.
 * Também exibe informações sobre a jogada realizada.
 */
void makeBotMove();

/**
 * @brief Avalia o estado atual do tabuleiro
 * 
 * Retorna uma pontuação baseada no estado do jogo:
 * - +10: BOT venceu
 * - -10: PLAYER venceu
 * - 0: Empate
 * 
 * @return Pontuação do estado atual
 */
int evaluateBoard();

#endif // MINIMAX_H