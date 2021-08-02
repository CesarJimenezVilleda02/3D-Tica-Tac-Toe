#include <vector>

#include "../include/Board.h"

Board::Board() {
    this->board = {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
};

std::vector <std::vector <char>> Board::getBoard() {
    return this->board;
}

bool Board::addSymbolToBoard(char playerSymbol, int posRow, int posCol) {
    posRow--;
    posCol--;

    if (this->board[posRow][posCol] != '_') return false;

    this->board[posRow][posCol] = playerSymbol;

    return true;
};

bool Board::checkBoardForWin() {
    for (std::vector <char> row : this->board) {
        if (row[0]!='_' && row[0] == row[1] && row[1] == row[2]) return true;
    }

    for (int i = 0; i < 3; i++) {
        if(this->board[0][i] != '_' && this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]) return true;
    }

    if(this->board[0][0] != '_' && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) return true;
    else if(this->board[0][2] !='_' && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]) return true;

    return false;

}