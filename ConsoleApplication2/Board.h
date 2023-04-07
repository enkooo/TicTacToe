#pragma once
#include <iostream>
#include "Player.h"

class Board {
public:
    Board() : board_(9, ' ') {}

    ~Board() {}

    bool isGameOver() const {
        return isTie() || getWinner() != ' ';
    }

    bool isTie() const {
        for (int i = 0; i < 9; ++i) {
            if (board_[i] == ' ') {
                return false;
            }
        }

        return getWinner() == ' ';
    }

    char getWinner() const {
        for (int i = 0; i < 9; i += 3) {
            if (board_[i] != ' ' && board_[i] == board_[i + 1] && board_[i] == board_[i + 2]) {
                return board_[i];
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (board_[i] != ' ' && board_[i] == board_[i + 3] && board_[i] == board_[i + 6]) {
                return board_[i];
            }
        }

        if (board_[0] != ' ' && board_[0] == board_[4] && board_[0] == board_[8]) {
            return board_[0];
        }

        if (board_[2] != ' ' && board_[2] == board_[4] && board_[2] == board_[6]) {
            return board_[2];
        }

        return ' ';
    }

    bool makeMove(int index, char player) {
        if (index < 0 || index >= 9) {
            return false;
        }

        if (board_[index] != ' ') {
            return false;
        }

        board_[index] = player;

        return true;
    }

    const std::vector<char>& getBoard() const {
        return board_;
    }

private:
    std::vector<char> board_;
};

