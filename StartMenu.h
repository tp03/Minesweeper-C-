#pragma once
#include "MenuElement.h"
#include "ChooseGameMenu.h"
#include "RankingHUD.h"
#include "Ranking.h"


class StartMenu :
	public MenuElement
{
	void enterKeyAction();
	void playButtonAction();
	void rankingButtonAction();
	void exitButtonAction();

public:
	StartMenu(int width, int height, sf::RenderWindow* window);

	virtual void run();
};
