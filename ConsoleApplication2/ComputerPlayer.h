#pragma once
#include "Player.h"
class ComputerPlayer : public Player {
public:
    int makeMove() override {
        srand(time(NULL));  
        return rand() % 9;  
    }
};


