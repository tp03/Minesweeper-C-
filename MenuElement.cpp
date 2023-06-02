#include "MenuElement.h"


MenuElement::MenuElement(int w, int h, sf::RenderWindow* win)
	:width(w), height(h), window(win)
{
	if (!font.loadFromFile("Modern.ttf"))
	{
		std::cerr << "Failed to load font.";
	}
}

void MenuElement::setButtons()
{
	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		selectedButtonIndex = i;

		if (i == 0)
		{
			highlightButton();
			y_pos = y_pos_unit * (BUTTONS_NUMBER + i) - (1.5 * font_size);
		}
		else
		{
			unhighlightButton();
			y_pos = y_pos_unit * (BUTTONS_NUMBER + i) - (0.75 * font_size);
		}

		buttons[i].setFont(font);
		buttons[i].setPosition(sf::Vector2f(x_pos, y_pos));
	}
}

void MenuElement::draw()
{
	window->clear();

	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		window->draw(buttons[i]);
	}

	window->display();
}

void MenuElement::highlightButton()
{
	int new_x_pos = buttons[selectedButtonIndex].getPosition().x;
	int new_y_pos = buttons[selectedButtonIndex].getPosition().y - (0.75 * font_size);

	buttons[selectedButtonIndex].setFillColor(sf::Color::Red);
	buttons[selectedButtonIndex].setCharacterSize(2 * font_size);
	buttons[selectedButtonIndex].setPosition(sf::Vector2f(new_x_pos, new_y_pos));
}

void MenuElement::unhighlightButton()
{
	int new_x_pos = buttons[selectedButtonIndex].getPosition().x;
	int new_y_pos = buttons[selectedButtonIndex].getPosition().y + (0.75 * font_size);

	buttons[selectedButtonIndex].setFillColor(sf::Color::White);
	buttons[selectedButtonIndex].setCharacterSize(font_size);
	buttons[selectedButtonIndex].setPosition(sf::Vector2f(new_x_pos, new_y_pos));
}

void MenuElement::upKeyAction()
{
	if (selectedButtonIndex - 1 >= 0)
	{
		unhighlightButton();
		selectedButtonIndex--;
		highlightButton();
	}
}

void MenuElement::downKeyAction()
{
	if (selectedButtonIndex + 1 < BUTTONS_NUMBER)
	{
		unhighlightButton();
		selectedButtonIndex++;
		highlightButton();
	}
}
