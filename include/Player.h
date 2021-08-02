#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    char Symbol;
    std::string Name;
    public:
        Player();
        Player(char, std::string);
        std::string getName();
        char getSymbol();
};

#endif 