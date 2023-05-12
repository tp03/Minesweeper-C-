#pragma once
#include <vector>
#include "Cell.h"

class Board {
public:
    Board(int width, int height, int numMines);
    
    int getWidth();
    int getHeight();
    int getNumMines();
    
private:
    void initializeBoard();
    void placeMines();
    void calculateAdjacentMines();

    std::vector<std::vector<Cell*>> cells;
    int width;
    int height;
    int numMines;
};