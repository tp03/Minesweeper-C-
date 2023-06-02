#pragma once
#include "MenuElement.h"
#include "MenuChooseGame.h"
#include "RankingHUD.h"
#include "MenuRanking.h"


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
