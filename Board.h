#pragma once
#include <vector>
#include "Cell.h"
#include "Player.h"

class Board {
public:
    Board(int width = 0, int height = 0, int numMines = 0);
    ~Board();

    int getWidth();
    int getHeight();
    int getNumMines();
    std::vector<std::vector<Cell*>> getBoard();

    bool isCellOpen(int x, int y);
    bool isCellFlag(int x, int y);
    bool isCellMine(int x, int y);

    void openCell(int x, int y);
    void flagCell(int x, int y);
    void unflagCell(int x, int y);

    void rightClicked(sf::Vector2i mousePosition);
    int getAdjacentMines(int x, int y);

    void saveBoard(const Player& player);//to musi być przypisane do przycisku w menu
    void loadBoard(const Player& player);//to musi być przypisane do przycisku w menu
private:
    void initializeBoard();
    void placeMines();
    void calculateAdjacentMines();

    std::vector<std::vector<Cell*>> cells;
    int width;
    int height;
    int numMines;
};
