#include "Game.h"
#include <iostream>

Game::Game(int difficulty, std::string& playerName) {
    switch (difficulty)
    {
    case 0:
        board_ = Board(8,8,10);
        break;
    case 1:
        board_ = Board(13,13,25);
        break;
    case 2:
        board_ = Board(17,17,60);
        break;
    default:
        board_ = Board(8,8,10);
        break;
    }
    player_ = Player(playerName);
}

void Game::start() {
    GameInterface game();
    game.showBoard(board_);
}