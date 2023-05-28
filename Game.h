#pragma once
#include "Board.h"
#include "Player.h"
#include "GameInterface.h"

class Game {
public:
    Game(int difficulty, std::string& playerName);
    void start();

private:
    Board board_;
    Player player_;
};