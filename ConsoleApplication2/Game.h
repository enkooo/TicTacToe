#pragma once
#include <memory>
#include "Board.h"


class Game {
public:
    Game() {
        board_ = new Board();
    }

    ~Game() {
        delete board_;
        board_ = nullptr;
    }

    bool makeMove(int index) {
        char player = currentPlayer();
        bool success = board_->makeMove(index, player);
        if (success) {
            moves_.push_back(index);
            currentPlayer_ = (currentPlayer_ == 'X' ? 'O' : 'X');
        }
        return success;
    }

    char currentPlayer() const {
        if (moves_.empty() || moves_.size() % 2 == 0) {
            return 'X';
        }
        else {
            return 'O';
        }
    }

    const std::string getStatus() const {
        if (board_->isGameOver()) {
            char winner = board_->getWinner();
            if (winner != ' ') {
                return std::string("Winner: ") + winner;
            }
            else {
                return "Tie";
            }
        }
        else {
            return std::string("Current player: ") + currentPlayer();
        }
    }

    void display() const {
        const vector<char>& board = board_->getBoard();
        std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
        std::cout << "---+---+---" << std::endl;
        std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
        std::cout << "---+---+---" << std::endl;
        std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    }

private:
    Board* board_;
    std::vector<int> moves_;
    char currentPlayer_ = 'X';
};


