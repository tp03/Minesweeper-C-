#include "Menu.h"


Menu::Menu(int w, int h, sf::RenderWindow* win)
	: width(w), height(h), window(win)
{
	if (!font.loadFromFile("Modern.ttf"))
	{
		std::cout << "Failed to load font.";
	}

	font_size = height / 12;
	x_pos = width / 10;
	y_pos_unit = height / (2 * BUTTONS_NUMBER);

	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		selectedButtonIndex = i;
		buttons[i].setFont(font);

		if (i == 0) highlightButton();
		else unhighlightButton();
	}

	selectedButtonIndex = 0;
	buttons[0].setString("Play");
	buttons[1].setString("Ranking");
	buttons[2].setString("Exit");
}

void Menu::highlightButton()
{
	y_pos = y_pos_unit * (BUTTONS_NUMBER + selectedButtonIndex) - (1.5 * font_size);

	buttons[selectedButtonIndex].setFillColor(sf::Color::Red);
	buttons[selectedButtonIndex].setCharacterSize(font_size * 2);
	buttons[selectedButtonIndex].setPosition(sf::Vector2f(x_pos, y_pos));
}

void Menu::unhighlightButton()
{
	y_pos = y_pos_unit * (BUTTONS_NUMBER + selectedButtonIndex) - (0.75 * font_size);

	buttons[selectedButtonIndex].setFillColor(sf::Color::White);
	buttons[selectedButtonIndex].setCharacterSize(font_size);
	buttons[selectedButtonIndex].setPosition(sf::Vector2f(x_pos, y_pos));
}