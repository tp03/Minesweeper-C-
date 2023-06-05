#include "Ranking.h"


Ranking::Ranking(int w, int h, sf::RenderWindow* win, std::string f_name)
	: MenuElement(w, h, win), file_name(f_name)
{
	font_size = height / (2 * ITEMS_NUMBER);
	x_pos = width / 10;
	y_pos_unit = height / (ITEMS_NUMBER + 3);

	escape_clicked = false;
	right_clicked = false;
	left_clicked = false;

	cursor_index = 0;

	loadPlayerList();
	setRankingList();
}


void Ranking::draw()
{
	for (int i = 0; i < std::min(ITEMS_NUMBER, int(nicknames.size())); ++i)
	{
		window->draw(ranking_places[i]);
		window->draw(ranking_nicknames[i]);
		window->draw(ranking_scores[i]);
	}
}

void Ranking::loadPlayerList()
{
	Reader* reader;
	reader = new Reader(file_name);

	nicknames = reader->returnNicknameList();
	scores = reader->returnScoreList();

	delete reader;
}

void Ranking::setRankingList()
{
	for (int i = 0; i < std::min(ITEMS_NUMBER, int(nicknames.size())); ++i)
	{
		y_pos = y_pos_unit * (i + 3) - (0.75 * font_size);

		ranking_places[i].setFont(font);
		ranking_places[i].setFillColor(sf::Color::White);
		ranking_places[i].setCharacterSize(font_size);
		ranking_places[i].setPosition(
			sf::Vector2f(x_pos - font_size, y_pos)); //left side
		ranking_places[i].setString(std::to_string(i + 1) + ".");

		ranking_nicknames[i].setFont(font);
		ranking_nicknames[i].setFillColor(sf::Color::White);
		ranking_nicknames[i].setCharacterSize(font_size);
		ranking_nicknames[i].setPosition(
			sf::Vector2f(x_pos + 2 * font_size, y_pos)); //on the right side of place
		ranking_nicknames[i].setString(nicknames[i]);

		ranking_scores[i].setFont(font);
		ranking_scores[i].setFillColor(sf::Color::White);
		ranking_scores[i].setCharacterSize(font_size);
		ranking_scores[i].setPosition(
			sf::Vector2f(width - x_pos - font_size, y_pos)); //right side
		ranking_scores[i].setString(std::to_string(scores[i]));
	}
}

void Ranking::upKeyAction()
{
	if (cursor_index - 1 >= 0)
	{
		cursor_index--;
		scroll();
	}
}

void Ranking::downKeyAction()
{
	if (cursor_index < int(nicknames.size() - ITEMS_NUMBER))
	{
		cursor_index++;
		scroll();
	}
}

void Ranking::rightKeyAction()
{
	right_clicked = true;
}

void Ranking::leftKeyAction()
{
	left_clicked = true;
}

void Ranking::escapeKeyAction()
{
	escape_clicked = true;
}

void Ranking::scroll()
{
	for (int i = 0; i < ITEMS_NUMBER; ++i)
	{
		ranking_places[i].setString(std::to_string(i + 1 + cursor_index) + ".");
		ranking_nicknames[i].setString(nicknames[i + cursor_index]);
		ranking_scores[i].setString(std::to_string(scores[i + cursor_index]));
	}
}

bool Ranking::escapeKeyClicked()
{
	return escape_clicked;
}

bool Ranking::rightKeyClicked()
{
	return right_clicked;
}

bool Ranking::leftKeyClicked()
{
	return left_clicked;
}

void Ranking::run()
{
	sf::Event event;

	right_clicked = false;
	left_clicked = false;

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				upKeyAction();
				break;

			case sf::Keyboard::Down:
				downKeyAction();
				break;

			case sf::Keyboard::Right:
				rightKeyAction();
				break;

			case sf::Keyboard::Left:
				leftKeyAction();
				break;

			case sf::Keyboard::Escape:
				escapeKeyAction();
				break;
			}
		}
		else if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	draw();
}
