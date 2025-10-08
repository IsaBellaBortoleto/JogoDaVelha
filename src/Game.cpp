#include "Game.h"
#include "Ui.h"
#include <iostream>

Game::Game() : currentEntityIndex(0), gameActive(false) {
  
}

Game::~Game() {

}

/**
 *  Adiciona um jogador ao jogo
 */
void Game::addEntity(Entity* player) {
    if (player != nullptr) {
        players.push_back(player);
    }
}

/**
 *  Inicia uma nova partida
 */
void Game::startNewGame() {
    board.initBoard();
    currentEntityIndex = 0;
    gameActive = true;
    
    cout << BOLD << ORANGE << "=== NOVA PARTIDA INICIADA ===" << RESET << endl;
    cout << "Jogadores:" << endl;
    for (size_t i = 0; i < players.size(); ++i) {
        cout << "- " << players[i]->getNome() << " (" 
             << players[i]->getSimbolo() << ")" << endl;
    }
    cout << endl;
}

/**
 *  Executa o loop principal do jogo
 */
void Game::playGame() {
    startNewGame();
    
    while (gameActive && !isGameOver()) {
        // Mostrar o tabuleiro
        board.printBoard();
        
        // Processar jogada do jogador atual
        if (processCurrentEntityTurn()) {
            // Verificar se o jogo terminou antes de trocar de jogador
            if (!isGameOver()) {
                switchToNextEntity();
            }
        }
    }
    
    // Mostrar resultado final
    board.printBoard();
    showGameResult();
}

/**
 * Processa a jogada do jogador atual
 */
bool Game::processCurrentEntityTurn() {
    Entity* current = getCurrentEntity();
    if (current == nullptr) {
        return false;
    }
    
    return current->fazerJogada(board);
}

/**
 *  Verifica se o jogo terminou
 */
bool Game::isGameOver() {
    string result = board.checkWinner();
    if (result != "none") {
        gameActive = false;
        return true;
    }
    return false;
}

/**
 *  Exibe o resultado final
 */
void Game::showGameResult() {
    string winner = board.checkWinner();
    
    cout << BOLD << MAGENTA << "=== RESULTADO FINAL ===" << RESET << endl;
    
    if (winner == "tie") {
        cout << ORANGE << "EMPATE! Ninguem venceu." << RESET << endl;
    } else if (winner != "none") {
        // Encontrar qual jogador venceu
        for (Entity* player : players) {
            if (player->getSimbolo() == winner[0]) {
                cout << BOLD << BLUE << "VITORIA DO " << player->getNome() 
                     << " (" << winner << ")!" << RESET << endl;
                break;
            }
        }
    }
    
    cout << BOLD << "Obrigado por jogar!" << RESET << endl;
}

/**
 * Alterna para o próximo jogador
 */
void Game::switchToNextEntity() {
    if (players.empty()) return;
    
    currentEntityIndex = (currentEntityIndex + 1) % players.size();
}

/**
 * Retorna o jogador atual
 */
Entity* Game::getCurrentEntity() {
    if (players.empty() || currentEntityIndex >= static_cast<int>(players.size())) {
        return nullptr;
    }
    return players[currentEntityIndex];
}

/**
 * Retorna referência ao tabuleiro
 */
Board& Game::getBoard() {
    return board;
}