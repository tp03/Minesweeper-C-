#pragma once
#include "MenuElement.h"


class RankingHUD :
	public MenuElement
{
	std::string file_name;

	sf::Text title, gamemode, exit, navigation;

	void draw();
	void setTitle();
	void setGamemode();
	void setExit();
	void setNavigation();

public:
	RankingHUD(int w, int h, sf::RenderWindow* win, std::string f_name);

	virtual void run();
};
