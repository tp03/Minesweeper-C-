#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#define BUTTONS_NUMBER 3

class Menu
{
	int width, height;

	int selectedButtonIndex;
	int font_size, x_pos, y_pos, y_pos_unit;

	sf::Font font;
	sf::Text buttons[BUTTONS_NUMBER];
	sf::RenderWindow* window;

	void drawMenu();
	void upKeyAction();
	void downKeyAction();
	void enterKeyAction();
	void playButtonAction();
	void rankingButtonAction();
	void highlightButton();
	void unhighlightButton();

public:
	Menu(int width, int height, sf::RenderWindow* window);

	int getSelectedButtonIndex();
};
