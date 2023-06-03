#pragma once
#include "MenuElement.h"
#include "Player.h"
#include "GameInterface.h"
#include "ChooseGamemodeMenu.h"


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
