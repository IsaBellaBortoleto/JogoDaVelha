#pragma once

#include <string>
using namespace std;

/**
 * @brief Biblioteca para gerenciamento do tabuleiro do jogo da velha
 * 
 * Esta biblioteca contém todas as funcionalidades relacionadas ao tabuleiro
 * do jogo da velha, incluindo inicialização, verificação de vitória e 
 * manipulação das posições.
 */

// Constantes do jogo
extern const char BOT;
extern const char PLAYER;
extern const int BOARD_SIZE;

// Tabuleiro global
extern char board[3][3];

/**
 * @brief Inicializa o tabuleiro com espaços vazios
 */
void initBoard();

/**
 * @brief Verifica se três posições são iguais e não vazias
 * @param a Primeira posição
 * @param b Segunda posição  
 * @param c Terceira posição
 * @return true se as três posições são iguais e não vazias
 */
bool equals3(char a, char b, char c);

/**
 * @brief Verifica o estado atual do jogo
 * @return String indicando o vencedor ('X', 'O'), 'tie' para empate ou 'none' se o jogo continua
 */
string checkWinner();

/**
 * @brief Conta quantas posições estão vazias no tabuleiro
 * @return Número de posições vazias
 */
int countEmptySpots();

/**
 * @brief Verifica se uma posição específica está vazia
 * @param row Linha (0-2)
 * @param col Coluna (0-2)
 * @return true se a posição está vazia
 */
bool isPositionEmpty(int row, int col);

/**
 * @brief Verifica se as coordenadas estão dentro dos limites do tabuleiro
 * @param row Linha (0-2)
 * @param col Coluna (0-2)
 * @return true se as coordenadas são válidas
 */
bool isValidPosition(int row, int col);

/**
 * @brief Faz uma jogada no tabuleiro
 * @param row Linha (0-2)
 * @param col Coluna (0-2)
 * @param player Jogador ('X' ou 'O')
 * @return true se a jogada foi bem-sucedida
 */
bool makeMove(int row, int col, char player);

/**
 * @brief Desfaz uma jogada no tabuleiro
 * @param row Linha (0-2)
 * @param col Coluna (0-2)
 */
void undoMove(int row, int col);

