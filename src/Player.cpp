#include "Player.h"
#include "Ui.h"
#include "Board.h"
#include <iostream>

/**
 * @brief Construtor da classe Player
 * @param nome Nome do jogador
 * @param simbolo Símbolo do jogador ('X' ou 'O')
 */
Player::Player(string nome, char simbolo) : Entity(nome, simbolo) {
}

/**
 * @brief Destrutor da classe Player
 */
Player::~Player() {
}



/**
 * @brief Faz uma jogada no tabuleiro especificado
 * @param board Referência para o tabuleiro onde fazer a jogada
 * @return true se a jogada foi bem-sucedida
 */
bool Player::fazerJogada(Board& board) {
    int row, col;
    
    cout << BOLD << BLUE << getNome() << ", eh sua vez! (Simbolo: " << getSimbolo() << ")" << RESET << endl;
    
    while (true) {
        cout << "Digite a linha (1-3): ";
        cin >> row;
        cout << "Digite a coluna (1-3): ";
        cin >> col;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "Entrada invalida! Digite apenas numeros." << RESET << endl;
            continue;
        }
        
        // Validar entrada do usuário (1-3)
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << RED << "Posicao invalida! Use coordenadas entre 1 e 3." << RESET << endl;
            continue;
        }
        
        // Converter para coordenadas internas (0-2)
        int internalRow = row - 1;
        int internalCol = col - 1;
        
        if (!board.isValidPosition(internalRow, internalCol)) {
            cout << RED << "Erro interno de validacao." << RESET << endl;
            continue;
        }
        
        if (!board.isPositionEmpty(internalRow, internalCol)) {
            cout << RED << "Posicao ja ocupada! Escolha outra." << RESET << endl;
            continue;
        }
        
        // Fazer a jogada no tabuleiro usando coordenadas internas (0-2)
        if (board.makeMove(internalRow, internalCol, getSimbolo())) {
            // Atualizar a posição interna da entidade (coordenadas internas)
            setPosition(internalRow, internalCol);
            cout << BLUE << "Jogada realizada com sucesso na posicao (" << row << ", " << col << ")!" << RESET << endl;
            return true;
        } else {
            cout << RED << "Erro ao fazer a jogada. Tente novamente." << RESET << endl;
        }
    }
}