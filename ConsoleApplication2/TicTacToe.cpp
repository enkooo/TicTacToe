

#include <iostream>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

int main() {
    Game game;
    HumanPlayer humanPlayer;
    ComputerPlayer computerPlayer;
    char currentPlayer = 'X';

    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "Player X goes first." << std::endl;

    while (game.getStatus().find("Winner") == std::string::npos) {
        game.display();
        std::cout << game.getStatus() << std::endl;
        if (game.getStatus() == "Tie") {
            break;
        }

        if (currentPlayer == 'X') {
            if (game.makeMove(humanPlayer.makeMove() - 1)) {
                std::cout << "Move accepted." << std::endl;
                currentPlayer = 'O';
                system("cls");
            }
            else {
                std::cout << "Invalid move. Try again." << std::endl;
            }
            std::cout << game.getStatus() << std::endl;
        }
        else {
            if (game.makeMove(computerPlayer.makeMove())) {
                currentPlayer = 'X';
            }
            system("cls");
            std::cout << game.getStatus() << std::endl;
        }
        
    }

    system("cls");
    game.display();
    std::cout << game.getStatus() << std::endl;

    return 0;
}

//#include <iostream>
//#include <thread>
//#include "Game.h"
//#include "HumanPlayer.h"
//#include "ComputerPlayer.h"
//
//void gameLoop(Game& game, HumanPlayer& humanPlayer, ComputerPlayer& computerPlayer, char& currentPlayer) {
//    while (game.getStatus().find("Winner") == std::string::npos) {
//        game.display();
//        std::cout << game.getStatus() << std::endl;
//        if (game.getStatus() == "Tie") {
//            break;
//        }
//
//        if (currentPlayer == 'X') {
//            if (game.makeMove(humanPlayer.makeMove() - 1)) {
//                std::cout << "Move accepted." << std::endl;
//                currentPlayer = 'O';
//                system("cls");
//            }
//            else {
//                std::cout << "Invalid move. Try again." << std::endl;
//            }
//            std::cout << game.getStatus() << std::endl;
//        }
//        else {
//            if (game.makeMove(computerPlayer.makeMove())) {
//                currentPlayer = 'X';
//            }
//            system("cls");
//            std::cout << game.getStatus() << std::endl;
//        }
//    }
//
//    system("cls");
//    game.display();
//    std::cout << game.getStatus() << std::endl;
//}
//
//int main() {
//    Game game;
//    HumanPlayer humanPlayer;
//    ComputerPlayer computerPlayer;
//    char currentPlayer = 'X';
//
//    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
//    std::cout << "Player X goes first." << std::endl;
//
//    std::thread gameThread(gameLoop, std::ref(game), std::ref(humanPlayer), std::ref(computerPlayer), std::ref(currentPlayer));
//
//    // reszta kodu (np. obs³uga interakcji u¿ytkownika)
//
//    gameThread.join();
//    return 0;
//}
