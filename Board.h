#pragma once
#include <vector>
#include "Cell.h"

class Board {
public:
    Board(int width, int height, int numMines);
    ~Board();

    int getWidth();
    int getHeight();
    int getNumMines();
    
    bool isCellOpen(int x, int y);
    bool isCellFlag(int x, int y);
    bool isCellMine(int x, int y);
private:
    void initializeBoard();
    void placeMines();
    void calculateAdjacentMines();

    std::vector<std::vector<Cell*>> cells;
    int width;
    int height;
    int numMines;
};