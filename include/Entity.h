#pragma once
#include <string>
using namespace std;

class Entity
{
protected:
    int x, y;          // Posição no tabuleiro
    int score;
    string nome;
    char simbolo;
public:
    //Construtor e Destrutor
    Entity(string nome, char simbolo);
    Entity(string nome, char simbolo, int x, int y);
    virtual ~Entity() = default;

    // Métodos para posição
    int getX() const;
    int getY() const;
    void setPosition(int x, int y);
        
    int getScore();
    void setScore(int score);
    char getSimbolo();
    string getNome();

    // Método virtual puro para realizar uma jogada
    virtual bool fazerJogada(class Board& board) = 0;


};