#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "Ranking.h"
#include "Game.h"
#include "ChooseGameMenu.h"

#define BUTTONS_NUMBER 3

class Menu
{
protected:
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
	Menu();

	int getSelectedButtonIndex();
	void run();
};



class ChooseGameMenu : public Menu
{
	int width, height;

	bool return_pressed;

	sf::Text buttons[BUTTONS_NUMBER];
	sf::RenderWindow* window;

	void drawMenu();
	void upKeyAction();
	void downKeyAction();
	void enterKeyAction();
	void newGameButtonAction();
	void loadSavedGameButtonAction();
	void returnButtonAction();
	void highlightButton();
	void unhighlightButton();

public:
	ChooseGameMenu(int width, int height, sf::RenderWindow* window);

	bool returnButtonPressed();
	void run();
};
