#include <string>

#include "../include/Player.h"

Player::Player() {
    this->Symbol = ' ';
    this->Name = " ";
}

Player::Player(char symbol, std::string name) {
    this->Symbol = symbol;
    this->Name = name;
}

std::string Player::getName() {
    return this->Name;
}

char Player::getSymbol() {
    return this->Symbol;
}