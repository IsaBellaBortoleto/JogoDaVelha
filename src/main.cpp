#include "board.h"
#include "minimax.h"
#include "ui.h"
#include <iostream>
using namespace std;
/**
 * @file main.cpp
 * @brief Arquivo principal do jogo da velha com IA
 * 
 * Este arquivo contém a lógica principal do jogo da velha,
 * utilizando as bibliotecas personalizadas para tabuleiro,
 * algoritmo Minimax e interface de usuário.
 * 
 * @date 2025
 */

/**
 * @brief Função principal que executa o loop do jogo
 * 
 * Controla o fluxo principal do jogo, alternando entre
 * jogadas do jogador humano e do BOT até que haja um
 * vencedor ou empate.
 * 
 * @return 0 se o programa executou com sucesso
 */
int main() {
    bool playAgain = true;
    
    while (playAgain) {
        // Inicializar o jogo
        initBoard();
        displayWelcomeMessage();
        
        char currentPlayer = PLAYER; // Jogador humano começa
        
        // Loop principal do jogo
        while (true) {
            string winner = checkWinner();
            
            // Verificar se o jogo terminou
            if (winner != "none") {
                printBoard();
                displayGameResult(winner);
                break;
            }
            
            // Alternar entre jogadores
            if (currentPlayer == PLAYER) {
                printBoard();
                if (getPlayerMove()) {
                    currentPlayer = BOT;
                }
                // Se a jogada falhou, continua sendo a vez do jogador
            } else {
                printBoard();
                makeBotMove();
                currentPlayer = PLAYER;
            }
        }
        
        // Perguntar se quer jogar novamente
        playAgain = askPlayAgain();
        
        if (playAgain) {
            clearScreen();
        }
    }
    
    cout << BOLD << YELLOW << "Obrigado por jogar!" << RESET << endl;
    
    return 0;
}