#pragma once
#include "MenuElement.h"
#include "Player.h"
#include "GameInterface.h"


class ChooseGamemodeMenu :
	public MenuElement
{
	bool return_pressed;

	void enterKeyAction();
	void easyModeButtonAction();
	void normalModeButtonAction();
	void hardModeButtonAction();
	void returnButtonAction();

public:
	ChooseGamemodeMenu(int width, int height, sf::RenderWindow* window);

	bool returnButtonPressed();
	virtual void run();
};
