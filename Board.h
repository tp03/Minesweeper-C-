#pragma once
#include <vector>
#include "Cell.h"

class Board {
private:
    void initializeBoard();
    void placeMines();
    void calculateAdjacentMines();

    std::vector<std::vector<Cell*>> cells;
    int width;
    int height;
    int numMines;
};