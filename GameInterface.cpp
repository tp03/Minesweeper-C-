#include "GameInterface.h"
#include "Board.h"


int GameInterface::getDifficultyLevel() const {

	return difficulty_level;
}

void GameInterface::showBoard(Board board) const {

	int width = board.getWidth();
	int height = board.getHeight();
	std::vector<std::vector<Cell*>> vectors = board.getBoard();

	int pixels_x;
	int pixels_y;

	if (getDifficultyLevel() == 0)
	{
		pixels_x = 800;
		pixels_y = 800;
	}

	else if (getDifficultyLevel() == 1)
	{
		pixels_x = 1600;
		pixels_y = 1600;
	}

	else
	{
		pixels_x = 1600;
		pixels_y = 3000;
	}

	sf::RenderWindow window(sf::VideoMode(pixels_x, pixels_y), "Minesweeper");



	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed())
			{
				window.close();
			}
		}
		window.clear();
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				window.draw(vectors[x][y]->reveal());
			}
		}
		window.display();
	}

}