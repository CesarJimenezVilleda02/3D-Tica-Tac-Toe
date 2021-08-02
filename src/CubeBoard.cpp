#include <vector>
#include <iostream>

#include "../include/CubeBoard.h"

#include "../include/Board.h"
#include "../include/Player.h"

CubeBoard::CubeBoard() {
    this->Cube = {Board(),Board(),Board()};
}

void CubeBoard::displayBoards() {
    std::cout << "     " << "               BOARDS              " << std::endl;
    std::cout << "     " << "     1     |     2     |     3     " << std::endl;
    std::cout << "     " << "-----------------------------------" << std::endl;
    std::cout << "     " << "               Columns             " << std::endl;
    std::cout << "Rows " << " 1 | 2 | 3   1 | 2 | 3   1 | 2 | 3 " << std::endl;
    for(int i = 0; i<3; i++) {
    std::cout << "     " << "-----------------------------------" << std::endl;
    std::cout << i+1 << "->   " << this->Cube[0].getBoard()[i][0] <<" | "<< this->Cube[0].getBoard()[i][1] <<" | "<< this->Cube[0].getBoard()[i][2] <<"   "<< this->Cube[1].getBoard()[i][0] <<" | "<< this->Cube[1].getBoard()[i][1] <<" | "<< this->Cube[1].getBoard()[i][2] <<"   "<< this->Cube[2].getBoard()[i][0] <<" | "<< this->Cube[2].getBoard()[i][1] <<" | "<< this->Cube[2].getBoard()[i][2] <<" " << std::endl;
    
    }
    std::cout << "     " << "-----------------------------------\n" << std::endl;
}

bool CubeBoard::placeSymbolInCube(Player player, int board, int row, int col) {
    char symbol = player.getSymbol();
    if(this->Cube[board-1].addSymbolToBoard(symbol,row,col)) return true;
    else return false;
}



bool CubeBoard::checkCubeForWins() {
    char symbolInCenter = this->Cube[1].getBoard()[1][1];

    for(int i = 0; i < 3; i++) {

        // check individual wins in boards
        if(this->Cube[i].checkBoardForWin()) return true;

        //check for skew win patterns from top aristas
        if(this->Cube[0].getBoard()[0][i] != '_' && this->Cube[0].getBoard()[0][i] == this->Cube[1].getBoard()[1][i] && this->Cube[1].getBoard()[1][i] == this->Cube[2].getBoard()[2][i]) return true;
        //check for skew patterns from botton aristas
        else if(this->Cube[0].getBoard()[2][i] != '_' && this->Cube[0].getBoard()[2][i] == this->Cube[1].getBoard()[1][i] && this->Cube[1].getBoard()[1][i] == this->Cube[2].getBoard()[0][i])return true;
        //check for skew patterns from right side aristas
        else if(this->Cube[0].getBoard()[i][0] != '_' && this->Cube[0].getBoard()[i][0] == this->Cube[1].getBoard()[i][1] && this->Cube[1].getBoard()[i][1] == this->Cube[2].getBoard()[i][2]) return true;
        //check for skew patterns from left side aristas
        else if(this->Cube[0].getBoard()[i][2] != '_' && this->Cube[0].getBoard()[i][2] == this->Cube[1].getBoard()[i][1] && this->Cube[1].getBoard()[i][1] == this->Cube[2].getBoard()[i][0]) return true;

        // check if there is a win combination in the same cells but in different boards
        for(int j = 0; j < 3; j++) {
            if(this->Cube[0].getBoard()[i][j] != '_' && this->Cube[0].getBoard()[i][j] ==  this->Cube[1].getBoard()[i][j] && this->Cube[1].getBoard()[i][j] == this->Cube[2].getBoard()[i][j]) return true;
        }
    }

    // check for wins in diagonals  from a vertex to the vertex on the contrary side
    // top vertex
    if (this->Cube[0].getBoard()[0][0] != '_' && this->Cube[0].getBoard()[0][0] == symbolInCenter && symbolInCenter == this->Cube[2].getBoard()[2][2]) return true;
    else if (this->Cube[0].getBoard()[0][2] != '_' && this->Cube[0].getBoard()[0][2] == symbolInCenter && symbolInCenter == this->Cube[2].getBoard()[2][0]) return true;
    // bottom vertex
    else if (this->Cube[0].getBoard()[2][0] != '_' && this->Cube[0].getBoard()[2][0] == symbolInCenter && symbolInCenter == this->Cube[2].getBoard()[0][2]) return true;
    else if (this->Cube[0].getBoard()[2][2] != '_' && this->Cube[0].getBoard()[2][2] == symbolInCenter && symbolInCenter == this->Cube[2].getBoard()[0][0]) return true;

    return false;
}