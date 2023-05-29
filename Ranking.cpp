#include "Ranking.h"

using json = nlohmann::json;

Ranking::Ranking(int w, int h, sf::RenderWindow* win, std::string f_name)
	: width(w), height(h), window(win), file_name(f_name)
{
	if (!font.loadFromFile("Modern.ttf"))
	{
		std::cout << "Failed to load font.";
	}

	font_size = height / (2 * ITEMS_NUMBER);
	x_pos = width / 10;
	y_pos_unit = height / (ITEMS_NUMBER + 3);

	escape_clicked = false;
	right_clicked = false;
	left_clicked = false;

	cursorIndex = 0;

	readFromFile();
	setRankingList();
	setHUD();
}

void Ranking::readFromFile()
{
	std::ifstream file(file_name);

	if (file.good())
	{
		try
		{
			json data = json::parse(file);

			for (int i = 0; i < data.size(); ++i)
			{
				nicknames.push_back(data[i]["name"]);
				scores.push_back(data[i]["score"]);
			}
		}
		catch (const json::parse_error& e)
		{
			file.close();
		}
	}

	for (int i = 0; i < int(nicknames.size() - 1); ++i)
	{
		int max_index = i;
		for (int j = i + 1; j < nicknames.size(); j++)
		{
			if (scores[j] > scores[max_index]) {
				max_index = j;
			}
		}
		std::swap(nicknames[i], nicknames[max_index]);
		std::swap(scores[i], scores[max_index]);
	}
}

void Ranking::drawRanking()
{
	window->clear();

	for (int i = 0; i < std::min(ITEMS_NUMBER, int(nicknames.size())); ++i)
	{
		window->draw(ranking_places[i]);
		window->draw(ranking_nicknames[i]);
		window->draw(ranking_scores[i]);
	}

	window->draw(HUD_title);
	window->draw(HUD_return);
	window->draw(HUD_navigation);
	window->draw(HUD_gamemode);

	window->display();
}

void Ranking::setHUD()
{
	HUD_title.setFont(font);
	HUD_title.setFillColor(sf::Color::Red);
	HUD_title.setCharacterSize(2 * font_size);
	HUD_title.setPosition(
		sf::Vector2f(x_pos - font_size, y_pos_unit - font_size)); //left top
	HUD_title.setString("Ranking");

	HUD_return.setFont(font);
	HUD_return.setFillColor(sf::Color{ 75, 75, 75, 255 }); //grey
	HUD_return.setCharacterSize(0.4 * font_size);
	HUD_return.setPosition(
		sf::Vector2f(width - 3 * font_size, height - 0.8 * font_size)); //bottom right corner
	HUD_return.setString("[ESC] Exit");

	HUD_navigation.setFont(font);
	HUD_navigation.setFillColor(sf::Color{ 75, 75, 75, 255 }); //grey
	HUD_navigation.setCharacterSize(0.4 * font_size);
	HUD_navigation.setPosition(
		sf::Vector2f(0.4 * font_size, height - 0.8 * font_size)); //bottom right corner
	HUD_navigation.setString("[<] Previous\t\t[v] Scrol down\t\t[^] Scroll up\t\t[>] Next");

	HUD_gamemode.setFont(font);
	HUD_gamemode.setFillColor(sf::Color::White);
	HUD_gamemode.setCharacterSize(0.8 * font_size);
	HUD_gamemode.setPosition(
		sf::Vector2f(width - 4 * x_pos, y_pos_unit + 0.2 * font_size)); //on the right side of title
	if (file_name[6] == '0') HUD_gamemode.setString("Easy Mode");
	else if (file_name[6] == '1') HUD_gamemode.setString("Normal Mode");
	else if (file_name[6] == '2') HUD_gamemode.setString("Hard Mode");
}

void Ranking::setRankingList()
{
	for (int i = 0; i < std::min(ITEMS_NUMBER, int(nicknames.size())); ++i)
	{
		y_pos = y_pos_unit * (i + 3) - (0.75 * font_size);

		ranking_places[i].setFont(font);
		ranking_places[i].setFillColor(sf::Color::White);
		ranking_places[i].setCharacterSize(font_size);
		ranking_places[i].setPosition(sf::Vector2f(x_pos - font_size, y_pos));
		ranking_places[i].setString(std::to_string(i + 1) + ".");

		ranking_nicknames[i].setFont(font);
		ranking_nicknames[i].setFillColor(sf::Color::White);
		ranking_nicknames[i].setCharacterSize(font_size);
		ranking_nicknames[i].setPosition(sf::Vector2f(x_pos + 2 * font_size, y_pos));
		ranking_nicknames[i].setString(nicknames[i]);

		ranking_scores[i].setFont(font);
		ranking_scores[i].setFillColor(sf::Color::White);
		ranking_scores[i].setCharacterSize(font_size);
		ranking_scores[i].setPosition(sf::Vector2f(width - x_pos - font_size, y_pos));
		ranking_scores[i].setString(std::to_string(scores[i]));
	}
}

void Ranking::upKeyAction()
{
	if (cursorIndex - 1 >= 0)
	{
		cursorIndex--;
		scroll();
	}
}

void Ranking::downKeyAction()
{
	if (cursorIndex < int(nicknames.size() - ITEMS_NUMBER))
	{
		cursorIndex++;
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
		ranking_places[i].setString(std::to_string(i + 1 + cursorIndex) + ".");
		ranking_nicknames[i].setString(nicknames[i + cursorIndex]);
		ranking_scores[i].setString(std::to_string(scores[i + cursorIndex]));
	}
}

bool Ranking::escapeClicked()
{
	return escape_clicked;
}

bool Ranking::rightClicked()
{
	return right_clicked;
}

bool Ranking::leftClicked()
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
	}

	drawRanking();
}