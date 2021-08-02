#ifndef CUBEBOARD_H
#define CUBEBOARD_H

#include <vector>

#include "./Board.h"
#include "./Player.h"

class CubeBoard {
    std::vector <Board> Cube;
    public:
        CubeBoard();
        void displayBoards();
        bool placeSymbolInCube(Player, int, int, int);
        bool checkCubeForWins();
};

#endif