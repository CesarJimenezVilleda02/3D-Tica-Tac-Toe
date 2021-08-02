#ifndef GAME_H
#define GAME_H

#include "./Player.h"
#include "./CubeBoard.h"

class Game {
    Player player1;
    Player player2;
    CubeBoard cube;
    public: 
        Game();
        Game(Player, Player);
        void init();
};

#endif