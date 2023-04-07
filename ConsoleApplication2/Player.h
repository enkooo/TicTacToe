#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Player {
public:
    virtual int makeMove() = 0;
};

