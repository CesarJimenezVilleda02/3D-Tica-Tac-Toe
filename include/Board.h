#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
    std::vector <std::vector <char>> board;
    public:
        Board();
        std::vector <std::vector <char>> getBoard();
        bool addSymbolToBoard(char, int, int);
        bool checkBoardForWin();
};

#endif