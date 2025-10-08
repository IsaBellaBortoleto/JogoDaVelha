#pragma once
#include "Entity.h"
#include "Board.h"

/**
 * Classe Bot que representa o jogador controlado por IA
 * 
 * Esta classe herda de Entity e implementa a estratégia minimax
 * para jogar de forma ótima contra o jogador humano.
 */
class Bot : public Entity {
private:
    /**
     * @brief Avalia o estado do tabuleiro
     * @param board Referência para o tabuleiro
     * @return Pontuação: +10 se bot ganhou, -10 se humano ganhou, 0 se empate
     */
    int evaluateBoard(Board& board);

    /**
     * @brief Algoritmo minimax para encontrar a melhor jogada
     * @param board Referência para o tabuleiro
     * @param depth Profundidade atual da busca
     * @param isMaximizing Se true, está maximizando (vez do bot)
     * @return Pontuação da melhor jogada
     */
    int minimax(Board& board, int depth, bool isMaximizing);

public:
 
    Bot(string nome, char simbolo);
    ~Bot();

    bool fazerJogada(Board& board) override;
};