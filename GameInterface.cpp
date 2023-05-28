#include "GameInterface.h"
#include "Board.h"
#include <sstream>
#include <iostream>


bool GameInterface::getWon() const {

	return has_won;
}

void GameInterface::setWon(bool b) {

	has_won = b;
}

void GameInterface::setLost(bool b) {

	has_lost = b;
}

bool GameInterface::getLost() const {

	return has_lost;
}

int GameInterface::getHeight() const {

	return height;
}

int GameInterface::getWidth() const {

	return width;
}

int GameInterface::getMines() const {

	return mine_count;
}

void GameInterface::checkIfWon() {

	int count = 0;

	for (int x = 0; x < getWidth(); x++) {
		for (int y = 0; y < getHeight(); y++) {

			if (board.isCellMine(x, y) == true)
			{
				if (board.isCellFlag(x, y) == true)
				{
					count++;
				}
				else {

					break;
				}
			}
		}
	}

	if (count == getMines())
	{
		setWon(true);
	}
}

void GameInterface::checkIfLost() {

	for (int x = 0; x < getWidth(); x++) {
		for (int y = 0; y < getHeight(); y++) {

			if (board.isCellMine(x, y) == true)
			{
				if (board.isCellOpen(x, y) == true)
				{
					setLost(true);
				}
			}

		}
	}
}


void EasyGame::playGame()
{
	Board b(8, 8, 9);
	board = b;
	showBoard(b);

}


void GameInterface::showBoard(Board board) const {

	int width = board.getWidth();
	int height = board.getHeight();

	int pixels_x = 100 * width;
	int pixels_y = 100 * height;

	sf::RenderWindow window(sf::VideoMode(pixels_x + 500, pixels_y), "Minesweeper");

	window.setFramerateLimit(60);
	srand(time(NULL));



	sf::Clock clock;

	sf::Time time;

	int seconds = 0;

	int hours = 0;

	int minutes = 0;

	sf::Font font;

	font.loadFromFile("arial.ttf");

	sf::Text text_clock("", font, 50);

	text_clock.setPosition(pixels_x + 200, pixels_y / 2);

	text_clock.setFillColor(sf::Color::Black);

	sf::Text text_time("TIME:", font, 40);

	text_time.setPosition(pixels_x + 200, pixels_y / 2 - 50);

	sf::Text text_fl("FLAGS LEFT:", font, 40);

	text_fl.setFillColor(sf::Color::Black);

	text_fl.setPosition(pixels_x + 200, pixels_y / 2 - 200);

	text_time.setFillColor(sf::Color::Black);

	sf::Text flags("", font, 50);

	flags.setPosition(pixels_x + 200, pixels_y / 2 - 150);

	flags.setFillColor(sf::Color::Black);


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
				else if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					board.leftClicked(mousePosition);
				}
			}
		}
		window.clear(sf::Color::White);
		std::stringstream stream;
		stream.str("");
		time = clock.getElapsedTime();

		seconds = time.asSeconds();

		hours = seconds / 3600;

		minutes = (seconds - (hours * 3600)) / 60;

		seconds = seconds - (hours * 3600 + minutes * 60);



		if (hours < 10)
		{

			stream << "0" << hours;

		}
		else
		{

			stream << hours;

		}
		if (minutes < 10)
		{

			stream << ":" << "0" << minutes;

		}
		else
		{

			stream << ":" << minutes;

		}
		if (seconds < 10)
		{

			stream << ":" << "0" << seconds;

		}
		else
		{

			stream << ":" << seconds;

		}

		std::stringstream flagss;

		flagss << board.flagsLeft();
		flags.setString(flagss.str());

		//checkIfWon();
		//checkIfLost();





		text_clock.setString(stream.str());
		window.draw(text_clock);
		window.draw(text_time);
		window.draw(flags);
		window.draw(text_fl);

		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				window.draw(board.getBoard()[x][y]->reveal());
			}
		}
		window.display();


	}

}