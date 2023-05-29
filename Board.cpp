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
    return numMines;
}

std::vector<std::vector<Cell*>> Board::getBoard()
{
    return cells;
}

bool Board::isCellOpen(int x, int y)
{
    return cells[x][y]->isOpen();
}

bool Board::isCellFlag(int x, int y)
{
    return cells[x][y]->isFlag();
}

bool Board::isCellMine(int x, int y)
{
    return cells[x][y]->isMine();
}

void Board::openCell(int x, int y) // Odkrywanie min
{
    if (!isCellOpen(x, y)) {

        cells[x][y]->setOpen(true);


        if (cells[x][y]->isMine()) {
            // Tutaj koniec gry
        }
        else if (getAdjacentMines(x, y) == 0) {

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        if (!isCellFlag(nx, ny)) {
                            openCell(nx, ny);
                        }
                    }
                }
            }
        }
    }
}


void Board::flagCell(int x, int y)
{
    if (!isCellOpen(x, y)) {
        cells[x][y]->setFlag(true);
    }
}

void Board::unflagCell(int x, int y)
{
    if (!isCellOpen(x, y)) {
        cells[x][y]->setFlag(false);
    }
}

int Board::getAdjacentMines(int x, int y)
{
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (cells[nx][ny]->isMine()) {
                    count++;
                }
            }
        }
    }
    return count;
}

void Board::saveBoard(const Player& player)
{
    std::ofstream outputFile(player.getName() + ".json");

    if (outputFile.is_open())
    {
        nlohmann::json boardData;

        for (int x = 0; x < getWidth(); ++x) {
            for (int y = 0; y < getHeight(); ++y) {
                bool isCellOpen = isCellOpen(x, y);
                bool isCellFlag = isCellFlag(x, y);
                bool isCellMine = isCellMine(x, y);

                nlohmann::json cellData;
                cellData["x"] = x;
                cellData["y"] = y;
                cellData["isCellOpen"] = isCellOpen;
                cellData["isCellFlag"] = isCellFlag;
                cellData["isCellMine"] = isCellMine;

                boardData.push_back(cellData);
            }
        }

        boardData["playerScore"] = player.getScore();

        outputFile << boardData.dump(4);
        outputFile.close();
        std::cout << "Board saved to " << player.getName() + ".json" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file: " << player.getName() + ".json" << std::endl;
    }
}

void Board::loadBoard(const Player& player)
{
    std::ifstream inputFile(player.getName() + ".json");

    if (inputFile.is_open())
    {
        nlohmann::json boardData;
        inputFile >> boardData;

        for (const auto& cellData : boardData)
        {
            int x = cellData["x"];
            int y = cellData["y"];
            bool isCellOpen = cellData["isCellOpen"];
            bool isCellFlag = cellData["isCellFlag"];
            bool isCellMine = cellData["isCellMine"];

            cells[x][y]->setMine(false);

            if (isCellOpen)
            {
                cells[x][y]->setOpen(true);
            }
            else if (isCellFlag)
            {
                cells[x][y]->setFlag(true);
            }
            else if (isCellMine)
            {
                cells[x][y]->setMine(true);
            }
        }

        calculateAdjacentMines();

        int playerScore = boardData["playerScore"];
        player.setScore(playerScore);

        inputFile.close();
        std::cout << "Board loaded from " << player.getName() + ".json" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file: " << player.getName() + ".json" << std::endl;
    }
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

int Board::flagsLeft()
{
    int count = numMines;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if (isCellFlag(x, y))
            {
                count--;
            }
        }
    }

    return count;
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

        if (!cells[x][y]->isMine()) {
            cells[x][y]->setMine(true);
            minesLeft--;
        }
    }
}

void Board::calculateAdjacentMines()
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (!cells[x][y]->isMine()) {


                int numAdjacentMines = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height && cells[nx][ny]->isMine()) {
                            numAdjacentMines++;
                        }
                    }
                }

                cells[x][y]->setAdjacentMines(numAdjacentMines);
            }
        }
    }
}

void Board::rightClicked(sf::Vector2i mouse_position)
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++)
        {

            if (cells[x][y]->isSpriteClicked(mouse_position))
            {
                if (isCellFlag(x, y))
                {
                    int am = cells[x][y]->getAdjacentMines();
                    int m = cells[x][y]->isMine();
                    cells[x][y] = new Closed(x, y);
                    cells[x][y]->setAdjacentMines(am);
                    cells[x][y]->setMine(m);
                }
                else if (!isCellOpen(x, y))
                {
                    cells[x][y] = new Flag(x, y, cells[x][y]->getAdjacentMines(), cells[x][y]->isMine());
                }
            }
        }
    }
}

void Board::leftClicked(sf::Vector2i mouse_position)
{
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++)
        {

            if (cells[x][y]->isSpriteClicked(mouse_position))
            {
                if (!isCellFlag(x, y) && !isCellOpen(x, y))
                {

                    if (isCellMine(x, y))
                    {
                        for (int x = 0; x < width; x++)
                        {
                            for (int y = 0; y < height; y++)
                            {
                                if (isCellMine(x, y))
                                {
                                    cells[x][y] = new Mine(x, y);
                                }
                                else
                                {
                                    cells[x][y] = new Numbered(x, y, cells[x][y]->getAdjacentMines());
                                }
                            }
                        }
                    }
                    else
                    {
                        openCell(x, y);
                        for (int x = 0; x < width; x++)
                        {
                            for (int y = 0; y < height; y++)
                            {
                                if (isCellOpen(x, y))
                                {
                                    cells[x][y] = new Numbered(x, y, cells[x][y]->getAdjacentMines());
                                }
                            }
                        }

                    }
                }


            }


        }


    }
