#pragma once

#include "Entity.h"
#include "Player.h"
#include "Board.h"
#include <vector>
#include <memory>

using namespace std;

/**
 * Classe Game que gerencia o jogo da velha
 * 
 * Esta classe implementa o padrão de agregação, contendo:
 * - Uma instância de Board (composição)
 * - Referências para Player (agregação)
 * Coordena o fluxo do jogo e mantém o estado.
 */
class Game {
private:
    Board board;                              
    vector<Entity*> players;            
    int currentEntityIndex;                 
    bool gameActive;                        

public:
   
    Game();
    ~Game();

    void addEntity(Entity* player);
    void startNewGame();
    void playGame();
    bool processCurrentEntityTurn();
    bool isGameOver();
    void showGameResult();
    void switchToNextEntity();
    Entity* getCurrentEntity();
    Board& getBoard();

};