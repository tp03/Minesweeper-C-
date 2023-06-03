#pragma once
#include "MenuElement.h"
#include "RankingHUD.h"
#include "Reader.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define ITEMS_NUMBER 10 //number of items displaying on ranking list

using json = nlohmann::json;


class Ranking :
	public MenuElement
{
	int cursor_index;

	bool escape_clicked, right_clicked, left_clicked;

	std::string file_name;

	std::vector <std::string> nicknames;
	std::vector <int> scores;

	sf::Text ranking_places[ITEMS_NUMBER];
	sf::Text ranking_nicknames[ITEMS_NUMBER];
	sf::Text ranking_scores[ITEMS_NUMBER];

	void loadPlayerList();
	void setRankingList();
	void draw();
	void upKeyAction();
	void downKeyAction();
	void rightKeyAction();
	void leftKeyAction();
	void escapeKeyAction();
	void scroll();

public:
	Ranking(int w, int h, sf::RenderWindow* win, std::string f_name);

	bool escapeKeyClicked();
	bool rightKeyClicked();
	bool leftKeyClicked();

	virtual void run();
};

