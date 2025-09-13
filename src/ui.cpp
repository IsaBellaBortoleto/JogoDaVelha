#include "../include/ui.h"
#include "../include/board.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

void printBoard() {
    cout << WHITE << "\n-------------\n" << RESET;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << WHITE << "| " << RESET;

        for (int j = 0; j < BOARD_SIZE; ++j) {
            // Colorir X em vermelho e O em laranja
            if (board[i][j] == 'X') {
                cout << RED << board[i][j] << RESET;
            } else if (board[i][j] == 'O') {
                cout << ORANGE << board[i][j] << RESET;
            } else {
                cout << board[i][j];
            }
            
            cout << WHITE << " | " << RESET;
        }
        
        cout << "\n" << WHITE << "-------------\n" << RESET;
    }
    cout << "\n";
}

void displayWelcomeMessage() {
    cout << BOLD << YELLOW << "---- Bem vindo ao Jogo da Velha! ----" << RESET << endl;
    cout << YELLOW << "Voce eh " << ORANGE << "'O'" << YELLOW << " e o BOT eh " 
              << RED << "'X'" << YELLOW << "." << RESET << endl;
    cout << YELLOW << "As posicoes sao numeradas de 1 a 3 para linhas e colunas." << RESET << endl;
}

bool getPlayerMove() {
    int row, col;
    
    cout << BOLD << WHITE << "Eh a sua vez! " << RESET;
    cout << "Insira a linha (1-3): ";
    
    if (!(cin >> row)) {
        displayInvalidMoveError();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    
    cout << "Agora insira a coluna (1-3): ";
    if (!(cin >> col)) {
        displayInvalidMoveError();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    
    // Converter para índices baseados em 0
    row--;
    col--;
    
    // Validar jogada
    if (!isValidPosition(row, col) || !isPositionEmpty(row, col)) {
        displayInvalidMoveError();
        return false;
    }
    
    // Fazer a jogada
    if (makeMove(row, col, PLAYER)) {
        displayPlayerMove(row + 1, col + 1); // +1 para exibição baseada em 1
        return true;
    }
    
    return false;
}

void displayBotMove(int row, int col) {
    cout << MAGENTA << "BOT marcou (" << row << "," << col << "):" << RESET << endl;
}

void displayPlayerMove(int row, int col) {
    cout << BLUE << "Jogador marcou (" << row << "," << col << "):" << RESET << endl;
}

void displayGameResult(const std::string& winner) {
    cout << endl;
    if (winner == "tie") {
        cout << BOLD << YELLOW << "O jogo empatou!" << RESET << endl;
    } else if (winner == "X") {
        cout << BOLD << RED << "O BOT venceu!" << RESET << endl;
    } else if (winner == "O") {
        cout << BOLD << BLUE << "Voce venceu!" << RESET << endl;
    }
    cout << endl;
}

void displayInvalidMoveError() {
    cout << BOLD << RED << "Jogada invalida! Tente novamente." << RESET << endl;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void waitForEnter() {
    cout << "Pressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool askPlayAgain() {
    char response;
    cout << BOLD << WHITE << "Deseja jogar novamente? (s/n): " << RESET;
    cin >> response;
    return (response == 's' || response == 'S');
}