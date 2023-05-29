#pragma once
#include "SFML/Graphics.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define ITEMS_NUMBER 10

class Ranking
{
	int width, height;

	int cursorIndex;
	int font_size, x_pos, y_pos, y_pos_unit;

	bool escape_clicked, right_clicked, left_clicked;

	sf::Font font;
	sf::Text HUD_title, HUD_return, HUD_navigation, HUD_gamemode;
	sf::Text ranking_places[ITEMS_NUMBER];
	sf::Text ranking_nicknames[ITEMS_NUMBER];
	sf::Text ranking_scores[ITEMS_NUMBER];
	sf::RenderWindow* window;

	std::string file_name;
	std::vector <std::string> nicknames;
	std::vector <int> scores;

	void readFromFile();
	void drawRanking();
	void setHUD();
	void setRankingList();
	void upKeyAction();
	void downKeyAction();
	void rightKeyAction();
	void leftKeyAction();
	void escapeKeyAction();
	void scroll();

public:
	Ranking(int width, int height, sf::RenderWindow* window, std::string file_name);

	bool escapeClicked();
	bool rightClicked();
	bool leftClicked();

	void run();
};
