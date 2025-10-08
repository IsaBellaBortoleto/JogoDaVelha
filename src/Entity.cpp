#include "Entity.h"


Entity::Entity(string nome, char simbolo) 
    : x(-1), y(-1), score(0), nome(nome), simbolo(simbolo) {
}

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