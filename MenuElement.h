#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>


class MenuElement
{
protected:
	int buttons_number = 3; //number of buttons in menu
	int width, height;
	int font_size, x_pos, y_pos, y_pos_unit;
	int selectedButtonIndex;

	std::vector <sf::Text> buttons{ buttons_number };
	sf::RenderWindow* window;
	sf::Font font;
	std::string playerName;

	void draw();
	void setButtons();
	void highlightButton();
	void unhighlightButton();
	void upKeyAction();
	void downKeyAction();

public:
	MenuElement(int width, int height, sf::RenderWindow* window);

	virtual void run() = 0;
};
