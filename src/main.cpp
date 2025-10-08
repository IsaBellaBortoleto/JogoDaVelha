#include "Game.h"
#include "Player.h"
#include "Bot.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== JOGO DA VELHA =====" << endl;
    cout << "Use coordenadas de 1 a 3 para linha e coluna" << endl;
    cout << endl;
    
    // Criar jogo
    Game jogo;
    
    // Criar jogadores: Humano (X) e Bot (O)
    Player jogador("Jogador 1", 'X');
    Bot bot("Bot", 'O');
    
    // Adicionar jogadores ao jogo
    jogo.addEntity(&jogador);
    jogo.addEntity(&bot);
    
    // Iniciar e jogar
    jogo.playGame();
    
    return 0;
}