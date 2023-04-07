#pragma once
#include "Player.h"
#include <string>

class HumanPlayer : public Player {
public:
    int makeMove() override {
        int index;
        std::string input;

        while (true) {
            std::cout << "Enter the index of your move (1-9): ";
            std::cin >> input;

            try {
                index = std::stoi(input);
            }
            catch (const std::exception&) {
                std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
                continue;
            }

            if (index < 1 || index > 9) {
                std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            }
            else {
                break;
            }
        }

        return index;
    }
};



