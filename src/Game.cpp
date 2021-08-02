#include <iostream>
#include <vector>
#include <string>

#include "../include/CubeBoard.h"
#include "../include/Game.h"

Game::Game() {}

Game::Game(Player player1, Player player2) {
    this->player1 = player1;
    this->player2 = player2;
    this->cube = CubeBoard();
}

void Game::init() {
    int turn = 0;
    std::string currentPlayer;

    std::cout << "Hello " << player1.getName() << " and " << player2.getName() << ", to start " << player1.getName() << " shall choose the position of his symbol, then "<< player2.getName() << " and so forth."<< std::endl;
    std::cout << player1.getName() << " your symbol will be " << player1.getSymbol() << ", " << player2.getName() << " your symbol will be " << player2.getSymbol() << std::endl;
    
    do{
        turn++;
        currentPlayer =  turn % 2 ? this->player1.getName() : this->player2.getName();

        std::cout << "\n\n" << currentPlayer << " it is your turn. " << "TURN #" << turn << std::endl;
        this->cube.displayBoards();

        int board;
        int row;
        int col;

        while(true) {
            std::cout << "Insert the number of board where you want to place your symbol: ";
            std::cin >> board;
            std::cout << "Insert the number of row where you want to place your symbol: ";
            std::cin >> row;
            std::cout << "Insert the number of column where you want to place your symbol: ";
            std::cin >> col;

            if(this->cube.placeSymbolInCube(turn % 2 ? this->player1 : this->player2, board, row, col)) break;
            else std::cout << "You have selected a position already in use, please select a valid position.\n" << std::endl;

        };



    // } while (turn < 5);
    } while (!this->cube.checkCubeForWins());

    std::cout << "\n\n         GAME OVER!!!!";
    this->cube.displayBoards();
    std::cout << "\nCongratulations " << currentPlayer << " you are the winner of this game!!!\n" << std::endl;
}

int main () {
    std::string answer;
    while(true) {

        std::cout << "HELLO HUMANS, my name is Pablo Cesar Jimenez Villeda and my student id is A01703517" << std::endl;
        std::cout << "---Press any key to play 3D Tic-Tac-Toe, press 1 to exit the game---" << std::endl;
        std::cin >> answer;

        if(answer != "1") {
            std::string name1;
            std::string name2;

            std::cout << "Welcome to this awesome game humans, to start please write yout names." << std::endl;
            std::cout << "Player 1: ";
            std::cin >> name1; 
            std::cout << "Player 2: ";
            std::cin >> name2; 

            Player player1('O', name1);
            Player player2('X', name2);

            Game tictactoe(player1, player2);

            tictactoe.init();

        } else break;

    }

    return 0;
}