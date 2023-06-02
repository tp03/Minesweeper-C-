#pragma once
#include "MenuElement.h"


class ChooseGameMenu :
	public MenuElement
{
	bool return_pressed;

	void enterKeyAction();
	void newGameButtonAction();
	void savedGameButtonAction();
	void returnButtonAction();

public:
	ChooseGameMenu(int width, int height, sf::RenderWindow* window);

	bool returnButtonPressed();
	virtual void run();
};
