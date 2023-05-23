#include "GameInterface.h"
#include "Board.h"


void GameInterface::setPlaying(bool b) {

	still_playing = b;
}

bool GameInterface::getPlaying() const {

	return still_playing;
}

void GameInterface::showBoard(Board board) const {

	int width = board.getWidth();
	int height = board.getHeight();
	std::vector<std::vector<Cell*>> vectors = board.getBoard();

	int pixels_x = 100 * width;
	int pixels_y = 100 * height;

	sf::RenderWindow window(sf::VideoMode(pixels_x, pixels_y), "Minesweeper");



	while (window.isOpen()) {
		sf::Event evnt;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed())
			{
				window.close();
			}
			else if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Right)
				{
					board.rightClicked(mousePosition);
				}
			}
		}
		window.clear(sf::Color::White);
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				window.draw(board.getBoard()[x][y]->reveal());
			}
		}
		window.display();
	}

}