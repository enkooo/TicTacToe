

#include <iostream>
#include <fstream>
#include <thread>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

void saveResultToFile(std::ofstream& outputFile, const std::string& result) {
    outputFile << result << std::endl;
}

int main() {
    HumanPlayer* humanPlayer = new HumanPlayer();
    ComputerPlayer* computerPlayer = new ComputerPlayer();

    bool playAgain = true;

    std::ofstream outputFile;
    outputFile.open("results.txt");

    while (playAgain) {
        Game* game = new Game();
        char currentPlayer = 'X';

        std::cout << "Welcome to Tic Tac Toe!" << std::endl;
        std::cout << "Player X goes first." << std::endl;

        while (game->getStatus().find("Winner") == std::string::npos) {
            game->display();
            std::cout << game->getStatus() << std::endl;

            if (game->getStatus() == "Tie") {
                system("cls");
                break;
            }

            if (currentPlayer == 'X') {
                if (game->makeMove(humanPlayer->makeMove() - 1)) {
                    currentPlayer = 'O';
                }
            }
            else {
                if (game->makeMove(computerPlayer->makeMove())) {
                    currentPlayer = 'X';
                }
            }
            system("cls");
        }

        game->display();
        std::cout << game->getStatus() << std::endl;

        std::thread t(saveResultToFile, std::ref(outputFile), game->getStatus());

        delete game;
        game = nullptr;

        std::string input;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> input;

        if (input != "y") {
            playAgain = false;
        }
        system("cls");

        t.join();
    }

    outputFile.close();

    delete humanPlayer;
    humanPlayer = nullptr;

    delete computerPlayer;
    computerPlayer = nullptr;

    return 0;
}

