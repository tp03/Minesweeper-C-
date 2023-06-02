#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

#define BUTTONS_NUMBER 3 //number of buttons in menu


class MenuElement
{
protected:
	int width, height;
	int font_size, x_pos, y_pos, y_pos_unit;
	int selectedButtonIndex;

	sf::Text buttons[BUTTONS_NUMBER];
	sf::RenderWindow* window;
	sf::Font font;

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
