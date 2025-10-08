#pragma once
#include "Entity.h"
#include <string>
using namespace std;

/**
 * Classe que representa o jogador humano
 * 
 * Esta classe herda de Entity e implementa a funcionalidade específica
 * para o jogador humano, incluindo a realização de jogadas.
 */

class Player : public Entity {
    
public:
    //Construtor e Destrutor
    Player(string nome, char simbolo);
    ~Player();

    // Implementação do método fazerJogada para o jogador humano
    bool fazerJogada(Board& board) override;
};
