#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para max e min
#include <limits>    // Para numeric_limits

using namespace std;

// Códigos de cores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define WHITE   "\033[37m"
#define ORANGE  "\033[38;5;208m"
#define BOLD    "\033[1m"


// Estrutura para representar o tabuleiro
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Definição dos jogadores
const char BOT = 'X';
const char PLAYER = 'O';

// Protótipos das funções
void printBoard();
string checkWinner();
int minimax(bool isMaximizing);
void bestMove();
void playerMove();

// Função para exibir o tabuleiro no terminal
void printBoard() {
    cout << WHITE << "\n-------------\n" << RESET;
    for (int i = 0; i < 3; ++i) {
        cout << WHITE << "| " << RESET;

        // Colorir X em vermelho e O em laranja
        if (board[i][0] == 'X') cout << RED << board[i][0] << RESET;
        else if (board[i][0] == 'O') cout << ORANGE << board[i][0] << RESET;
        else cout << board[i][0];
        
        cout << WHITE << " | " << RESET;
        
        if (board[i][1] == 'X') cout << RED << board[i][1] << RESET;
        else if (board[i][1] == 'O') cout << ORANGE << board[i][1] << RESET;
        else cout << board[i][1];
        
        cout << WHITE << " | " << RESET;
        
        if (board[i][2] == 'X') cout << RED << board[i][2] << RESET;
        else if (board[i][2] == 'O') cout << ORANGE << board[i][2] << RESET;
        else cout << board[i][2];
        
        cout << WHITE << " |\n" << RESET;
        cout << WHITE << "-------------\n" << RESET;
    }
    cout << "\n";
}

// Função para checar se três casas são iguais
bool equals3(char a, char b, char c) {
    return (a == b && b == c && a != ' ');
}

// Verifica se há um vencedor ou se o jogo empatou
string checkWinner() {
    // Checagem horizontal
    for (int i = 0; i < 3; ++i) {
        if (equals3(board[i][0], board[i][1], board[i][2])) {
            return string(1, board[i][0]);
        }
    }
    // Checagem vertical
    for (int i = 0; i < 3; ++i) {
        if (equals3(board[0][i], board[1][i], board[2][i])) {
            return string(1, board[0][i]);
        }
    }
    // Checagem nas diagonais
    if (equals3(board[0][0], board[1][1], board[2][2])) {
        return string(1, board[0][0]);
    }
    if (equals3(board[2][0], board[1][1], board[0][2])) {
        return string(1, board[2][0]);
    }

    int openSpots = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                openSpots++;
            }
        }
    }

    if (openSpots == 0) {
        return "tie"; // Empate
    }

    return "none"; // Jogo continua
}

// Algoritmo Minimax
int minimax(bool isMaximizing) {
    string result = checkWinner();
    if (result != "none") {
        if (result == string(1, BOT)) return 10;
        if (result == string(1, PLAYER)) return -10;
        if (result == "tie") return 0;
    }

    if (isMaximizing) { // Vez do BOT (maximizar a pontuação)
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = BOT;
                    int score = minimax(false);
                    board[i][j] = ' ';
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else { // Vez do PLAYER (minimizar a pontuação)
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = PLAYER;
                    int score = minimax(true);
                    board[i][j] = ' ';
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

// Lógica do bot para encontrar a melhor jogada
void bestMove() {
    int bestScore = numeric_limits<int>::min();
    int moveI = -1, moveJ = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = BOT;
                int score = minimax(false); // Simula a jogada do PLAYER
                board[i][j] = ' '; // Desfaz a jogada
                if (score > bestScore) {
                    bestScore = score;
                    moveI = i;
                    moveJ = j;
                }
            }
        }
    }
    board[moveI][moveJ] = BOT;
    cout << MAGENTA << "BOT marcou (" << moveI+1 << "," << moveJ+1 << "):" << RESET << endl;
}

// Função para obter e validar a jogada do PLAYER 
void playerMove() {
    int i, j;
    while (true) {
        cout << BOLD << WHITE << "Eh a sua vez! " << RESET << "Insira a linha (1-3): ";
        cin >> i;
        cout << "Agora insira a coluna (1-3): ";
        cin >> j;

        if (cin.fail() || i < 1 || i > 3 || j < 1 || j > 3 || board[i-1][j-1] != ' ') {
            cout << BOLD << RED << "Jogada invalida! Tente novamente." << RESET << endl;
            cin.clear(); // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
        } else {
            break; // Sai do loop se a jogada for válida
        }
    }
    board[i-1][j-1] = PLAYER; 
    cout << BLUE << "Jogador 1 marcou (" << i << "," << j << "):" << RESET << endl;
}

// Função principal que contém o loop do jogo
int main() {
    cout << BOLD << YELLOW << "Bem vindo ao Jogo da Velha!" << RESET << endl;
    cout << YELLOW << "Voce eh " << BLUE << "'O'" << YELLOW << ". As casas sao numeradas de 1 a 3 para linhas e colunas.\n" << RESET;

    char currentPlayer = PLAYER;

    while (true) {
        string winner = checkWinner();
        if (winner != "none") {
            printBoard();
            if (winner == "tie") {
                cout << BOLD << YELLOW << "O jogo empatou!" << RESET << endl;
            } else {
                if (winner == "X") {
                    cout << BOLD << RED << "O BOT venceu!" << RESET << endl;
                } else {
                    cout << BOLD << BLUE << "Voce venceu!" << RESET << endl;
                }
            }
            break;
        }

        if (currentPlayer == PLAYER) {
            printBoard();
            playerMove();
            currentPlayer = BOT;
        } else {
            printBoard();
            bestMove();
            currentPlayer = PLAYER;
        }
    }

    return 0;
}
