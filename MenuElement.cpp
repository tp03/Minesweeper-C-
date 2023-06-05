#include "MenuElement.h"


MenuElement::MenuElement(int w, int h, sf::RenderWindow* win)
	:width(w), height(h), window(win)
{
	if (!font.loadFromFile("textures/Modern.ttf"))
	{
		std::cerr << "Failed to load font.";
	}
}

void MenuElement::setPlayerName(std::string name)
{
	playerName = name;
}

void MenuElement::setButtons()
{
	for (int i = 0; i < buttons_number; ++i)
	{
		selectedButtonIndex = i;

		if (i == 0)
		{
			highlightButton();
			y_pos = y_pos_unit * (buttons_number + i) - (1.5 * font_size);
		}
		else
		{
			unhighlightButton();
			y_pos = y_pos_unit * (buttons_number + i) - (0.75 * font_size);
		}

		buttons[i].setFont(font);
		buttons[i].setPosition(sf::Vector2f(x_pos, y_pos));
	}
}

void MenuElement::draw()
{
	window->clear();

	for (int i = 0; i < buttons_number; ++i)
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
	if (selectedButtonIndex + 1 < buttons_number)
	{
		unhighlightButton();
		selectedButtonIndex++;
		highlightButton();
	}
}

int MenuElement::getWidth()
{
	return width;
}

int MenuElement::getHeight()
{
	return height;
}

int MenuElement::getFontSize()
{
	return font_size;
}

int MenuElement::getXPos()
{
	return x_pos;
}

int MenuElement::getYPos()
{
	return y_pos;
}

int MenuElement::getYPosUnit()
{
	return y_pos_unit;
}

int MenuElement::getSelectedButtonIndex()
{
	return selectedButtonIndex;
}

int MenuElement::getButtonsNumber()
{
	return buttons_number;
}
