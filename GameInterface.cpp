#include "GameInterface.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>


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

int GameInterface::getScore() const
{
	return player_score;
}

void GameInterface::setScore(int score)
{
	player_score = score;
}

void EasyGame::playGame(Player& p)
{
	Board b(8, 8, 9);
	board = b;
	showBoard(b, 0, false);
	if (getWon())
	{
		int score = getScore();
		p.setScore(score);
		p.fixedSaveScore(0);
		againWonWindow(p, 0);
	}
	if (getLost())
	{
		againLostWindow(p, 0);
	}

}

void MediumGame::playGame(Player& p)
{
	Board b(16, 16, 40);
	board = b;
	showBoard(b, 0, false);

	if (getWon())
	{
		int score = getScore();
		p.setScore(score);
		p.fixedSaveScore(1);
		againWonWindow(p, 1);
	}
	if (getLost())
	{
		againLostWindow(p, 1);
	}
}

void HardGame::playGame(Player& p)
{
	Board b(23, 16, 60);
	board = b;
	showBoard(b, 0, false);

	if (getWon())
	{
		int score = getScore();
		p.setScore(score);
		p.fixedSaveScore(2);
		againWonWindow(p, 2);
	}
	if (getLost())
	{
		againLostWindow(p, 2);
	}

}

void LoadedGame::playGame(Player& p)
{

	int time;

	if (width == 8)
	{
		Board b(8, 8, 9);
		time = b.loadBoard();
		board = b;
		showBoard(b, time, true);
		if (getWon())
		{
			int score = getScore();
			p.setScore(score);
			p.fixedSaveScore(0);
			againWonWindow(p, 0);
		}
		if (getLost())
		{
			againLostWindow(p, 0);
		}

	}
	else if (width == 16)
	{
		Board b(16, 16, 40);
		time = b.loadBoard();
		board = b;
		showBoard(b, time, true);
		if (getWon())
		{
			int score = getScore();
			p.setScore(score);
			p.fixedSaveScore(1);
			againWonWindow(p, 1);
		}
		if (getLost())
		{
			againLostWindow(p, 1);
		}
	}
	else
	{
		Board b(23, 16, 60);
		time = b.loadBoard();
		board = b;
		showBoard(b, time, true);
		if (getWon())
		{
			int score = getScore();
			p.setScore(score);
			p.fixedSaveScore(2);
			againWonWindow(p, 2);
		}
		if (getLost())
		{
			againLostWindow(p, 2);
		}
	}



}

void GameInterface::showBoard(Board& board, int added_time = 0, bool game_loaded = false) {


	bool first_click;

	if (!game_loaded)
	{
		first_click = true;
	}
	else
	{
		first_click = false;
	}

	int width = board.getWidth();
	int height = board.getHeight();

	int pixels_x = 100 * width;
	int pixels_y = 100 * height;

	sf::RenderWindow window(sf::VideoMode(pixels_x + 500, pixels_y), "Minesweeper");

	window.setFramerateLimit(60);
	srand(time(NULL));



	sf::Clock clock;

	sf::Time time;

	bool stop_clock = false;

	int seconds = 0;

	int hours = 0;

	int minutes = 0;

	sf::Font font;

	sf::Texture saveExitTexture;
	saveExitTexture.loadFromFile("textures/zapis.png");

	sf::Sprite exitButton;
	exitButton.setTexture(saveExitTexture);
	exitButton.setPosition(pixels_x + 70, pixels_y - 200);


	font.loadFromFile("textures/Modern.ttf");

	sf::Text text_clock("", font, 50);

	text_clock.setPosition(pixels_x + 200, pixels_y / 2);

	text_clock.setFillColor(sf::Color::White);

	sf::Text text_time("TIME:", font, 40);

	text_time.setPosition(pixels_x + 200, pixels_y / 2 - 50);

	sf::Text text_fl("FLAGS LEFT:", font, 40);

	text_fl.setFillColor(sf::Color::White);

	text_fl.setPosition(pixels_x + 150, pixels_y / 2 - 200);

	text_time.setFillColor(sf::Color::White);

	sf::Text flags("", font, 50);

	flags.setPosition(pixels_x + 200, pixels_y / 2 - 150);

	flags.setFillColor(sf::Color::White);


	while (window.isOpen()) {
		sf::Event evnt;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && !first_click)
				{
					int t = time.asSeconds() + added_time;
					board.saveBoard(t);
					window.close();
				}

				if (evnt.mouseButton.button == sf::Mouse::Right)
				{
					board.rightClicked(mousePosition);
				}
				else if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					board.leftClicked(mousePosition, first_click);
					first_click = false;

				}
			}
		}
		window.clear();
		std::stringstream time_stream;

		if (!stop_clock)
		{
			time = clock.getElapsedTime();

		}

		seconds = time.asSeconds() + added_time;

		hours = seconds / 3600;

		minutes = (seconds - (hours * 3600)) / 60;

		seconds = seconds - (hours * 3600 + minutes * 60);



		if (hours < 10)
		{
			time_stream << "0" << hours;
		}
		else
		{
			time_stream << hours;
		}
		if (minutes < 10)
		{
			time_stream << ":" << "0" << minutes;
		}
		else
		{
			time_stream << ":" << minutes;
		}
		if (seconds < 10)
		{
			time_stream << ":" << "0" << seconds;
		}
		else
		{
			time_stream << ":" << seconds;
		}

		std::stringstream flagss;

		flagss << board.flagsLeft();
		flags.setString(flagss.str());
		text_clock.setString(time_stream.str());


		window.draw(exitButton);
		window.draw(text_clock);
		window.draw(text_time);
		window.draw(flags);
		window.draw(text_fl);

		int close_counter = 0;

		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				window.draw(board.getBoard()[x][y]->reveal());
				if (!board.isCellOpen(x, y) && !board.isCellFlag(x, y))
				{
					close_counter++;
				}
			}
		}


		window.display();

		if (close_counter == 0)
		{

			stop_clock = true;

			int flag_counter = 0;

			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {

					if (board.isCellFlag(x, y))
					{
						flag_counter++;
					}
				}
			}

			if (flag_counter == 0)
			{
				setLost(true);
				std::this_thread::sleep_for(std::chrono::seconds(3));
				window.close();

			}
			else
			{
				setWon(true);

				int player_time = time.asSeconds() + added_time;

				setScore(player_time);

				std::this_thread::sleep_for(std::chrono::seconds(3));
				window.close();

			}


		}


	}

}

void GameInterface::againLostWindow(Player& p, int level)
{

	sf::RenderWindow window(sf::VideoMode(800, 500), "LostMenu");

	sf::Texture tryAgainTexture;
	tryAgainTexture.loadFromFile("textures/try_again.png");

	sf::Texture exitTexture;
	exitTexture.loadFromFile("textures/exit.png");

	sf::Sprite tryAgainButton;
	tryAgainButton.setTexture(tryAgainTexture);
	tryAgainButton.setPosition(50, 250);

	sf::Sprite exitButton;
	exitButton.setTexture(exitTexture);
	exitButton.setPosition(450, 250);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

				if (tryAgainButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					window.close();
					if (level == 0)
					{
						EasyGame NewGame;
						NewGame.playGame(p);
					}
					if (level == 1)
					{
						MediumGame NewGame;
						NewGame.playGame(p);
					}
					if (level == 2)
					{
						HardGame NewGame;
						NewGame.playGame(p);
					}

				}

				if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					window.close();
				}
			}
		}

		sf::Font font;

		font.loadFromFile("textures/Modern.ttf");

		sf::Text lost_info("YOU HAVE LOST", font, 50);

		lost_info.setPosition(200, 50);

		lost_info.setFillColor(sf::Color::White);

		window.clear();
		window.draw(tryAgainButton);
		window.draw(exitButton);
		window.draw(lost_info);
		window.display();
	}

}

void GameInterface::againWonWindow(Player& p, int level)
{

	sf::RenderWindow window(sf::VideoMode(800, 500), "WonMenu");

	sf::Texture tryAgainTexture;
	tryAgainTexture.loadFromFile("textures/try_again.png");

	sf::Texture exitTexture;
	exitTexture.loadFromFile("textures/exit.png");

	sf::Sprite tryAgainButton;
	tryAgainButton.setTexture(tryAgainTexture);
	tryAgainButton.setPosition(50, 250);

	sf::Sprite exitButton;
	exitButton.setTexture(exitTexture);
	exitButton.setPosition(450, 250);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

				if (tryAgainButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					window.close();

					if (level == 0)
					{
						EasyGame NewGame;
						NewGame.playGame(p);
					}
					if (level == 1)
					{
						MediumGame NewGame;
						NewGame.playGame(p);
					}
					if (level == 2)
					{
						HardGame NewGame;
						NewGame.playGame(p);
					}

				}

				if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					window.close();
				}
			}
		}

		sf::Font font;

		int last_game_score = getScore();

		std::stringstream points;

		points << "YOUR SCORE:  ";
		points << last_game_score;

		sf::Text score_info(points.str(), font, 30);

		font.loadFromFile("textures/Modern.ttf");

		sf::Text won_info("YOU HAVE WON", font, 50);

		won_info.setPosition(200, 50);

		won_info.setFillColor(sf::Color::White);

		score_info.setPosition(200, 150);

		score_info.setFillColor(sf::Color::White);

		window.clear();
		window.draw(tryAgainButton);
		window.draw(exitButton);
		window.draw(won_info);
		window.draw(score_info);
		window.display();
	}

}