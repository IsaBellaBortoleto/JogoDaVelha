#pragma once

#include <string>

/**
 * @brief Biblioteca de interface de usuário para o jogo da velha
 * 
 * Esta biblioteca contém todas as funcionalidades relacionadas à
 * interface com o usuário, incluindo exibição do tabuleiro,
 * entrada de dados e mensagens do jogo.
 */

// Códigos de cores ANSI para formatação do terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define ORANGE  "\033[38;5;208m"
#define BOLD    "\033[1m"

/**
 * @brief Exibe o tabuleiro formatado no terminal
 * 
 * Mostra o tabuleiro com cores diferenciadas:
 * - X em vermelho (BOT)
 * - O em laranja (PLAYER)
 * - Bordas em branco
 */
void printBoard();

/**
 * @brief Exibe mensagem de boas-vindas e instruções do jogo
 */
void displayWelcomeMessage();

/**
 * @brief Solicita e valida a jogada do jogador humano
 * 
 * Pede ao usuário para inserir linha e coluna, valida a entrada
 * e garante que a posição seja válida e esteja vazia.
 * 
 * @return true se a jogada foi realizada com sucesso
 */
bool getPlayerMove();

/**
 * @brief Exibe mensagem sobre a jogada do BOT
 * @param row Linha da jogada (baseada em 1)
 * @param col Coluna da jogada (baseada em 1)
 */
void displayBotMove(int row, int col);

/**
 * @brief Exibe mensagem sobre a jogada do jogador
 * @param row Linha da jogada (baseada em 1)
 * @param col Coluna da jogada (baseada em 1)
 */
void displayPlayerMove(int row, int col);

/**
 * @brief Exibe o resultado final do jogo
 * @param winner String indicando o vencedor ("X", "O", "tie")
 */
void displayGameResult(const std::string& winner);

/**
 * @brief Exibe mensagem de erro para jogada inválida
 */
void displayInvalidMoveError();

/**
 * @brief Limpa a tela do terminal (multiplataforma)
 */
void clearScreen();

/**
 * @brief Pausa o programa esperando o usuário pressionar Enter
 */
void waitForEnter();

/**
 * @brief Pergunta se o jogador quer jogar novamente
 * @return true se o jogador quer jogar novamente
 */
bool askPlayAgain();

