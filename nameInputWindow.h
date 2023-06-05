#pragma once
#include "MenuElement.h"
#include "StartMenu.h"


class nameInputWindow :
	public MenuElement
{
	StartMenu* start_menu;

public:
	nameInputWindow(int width, int height, sf::RenderWindow* window);

	virtual void run();
	sf::Clock cursorClock;
	bool showCursor = true;
};
