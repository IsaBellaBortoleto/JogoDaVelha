#pragma once

#include <string>

/**
 * Biblioteca de interface de usuário para o jogo da velha
 * 
 * Esta biblioteca contém todas as funcionalidades relacionadas à
 * interface com o usuário, incluindo exibição do tabuleiro,
 * entrada de dados e mensagens do jogo.
 */

// Códigos de cores ANSI para formatação do terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define ORANGE  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"


void printBoard();
void displayWelcomeMessage();
bool getPlayerMove();
void displayBotMove(int row, int col);
void displayPlayerMove(int row, int col);
void displayGameResult(const std::string& winner);
void displayInvalidMoveError();
void clearScreen();
void waitForEnter();
bool askPlayAgain();

