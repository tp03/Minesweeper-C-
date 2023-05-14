#include "Board.h"
#include "Cell.h"
#include <random>

Board::Board(int width, int height, int numMines)
    : width(width), height(height), numMines(numMines)
{
    cells.resize(width, std::vector<Cell*>(height));

    initializeBoard();

}

Board::~Board()
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            delete cells[x][y];
        }
    }
}

int Board::getWidth()
{
    return width;
}

int Board::getHeight()
{
    return height;
}

int Board::getNumMines()
{
    return numMines();
}

bool Board::isCellOpen(int x, int y)
{
    return cells[x][y]->IsOpen();
}

bool Board::isCellFlag(int x, int y)
{
    return cells[x][y]->IsFlag();
}

bool Board::isCellMine(int x, int y)
{
    return cells[x][y]->IsMine();
}

void Board::initializeBoard()
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            cells[x][y] = new Closed(x, y);
        }
    }

    placeMines();
    calculateAdjacentMines();
}

void Board::placeMines()
{
    // Losowo stwarzam miny
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distX(0, width - 1);
    std::uniform_int_distribution<int> distY(0, height - 1);

    int minesLeft = numMines;
    while (minesLeft > 0) {

        int x = distX(gen);
        int y = distY(gen);

        if (!cells[x][y]->IsMine()) {
            cells[x][y]->setMine(true);
            minesLeft--;
        }
    }
}

void Board::calculateAdjacentMines()
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (!cells[x][y]->IsMine()) {


                int numAdjacentMines = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height && cells[nx][ny]->IsMine()) {
                            numAdjacentMines++;
                        }
                    }
                }

                cells[x][y]->setAdjacentMines(numAdjacentMines);
            }
        }
    }
}