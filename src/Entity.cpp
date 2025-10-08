#include "Entity.h"

/**
 * @brief Construtor da classe Entity
 * @param nome Nome da entidade
 * @param simbolo Símbolo da entidade ('X' ou 'O')
 */
Entity::Entity(string nome, char simbolo) 
    : x(-1), y(-1), score(0), nome(nome), simbolo(simbolo) {
}

/**
 * @brief Construtor da classe Entity com posição
 * @param nome Nome da entidade
 * @param simbolo Símbolo da entidade ('X' ou 'O')
 * @param x Posição x no tabuleiro
 * @param y Posição y no tabuleiro
 */
Entity::Entity(string nome, char simbolo, int x, int y) 
    : x(x), y(y), score(0), nome(nome), simbolo(simbolo) {
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

int Entity::getScore() {
    return score;
}

void Entity::setScore(int score) {
    this->score = score;
}

char Entity::getSimbolo() {
    return simbolo;
}

string Entity::getNome() {
    return nome;
}