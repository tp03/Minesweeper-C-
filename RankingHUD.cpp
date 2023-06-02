#include "RankingHUD.h"


RankingHUD::RankingHUD(int w, int h, sf::RenderWindow* win, std::string f_name)
	: MenuElement(w, h, win), file_name(f_name)
{
	x_pos = width / 10;
	y_pos_unit = height / 13;
	font_size = height / 20;

	setTitle();
	setGamemode();
	setExit();
	setNavigation();
}

void RankingHUD::draw()
{
	window->draw(title);
	window->draw(gamemode);
	window->draw(exit);
	window->draw(navigation);
}

void RankingHUD::setTitle()
{
	title.setFont(font);
	title.setFillColor(sf::Color::Red);
	title.setCharacterSize(2 * font_size);
	title.setPosition(
		sf::Vector2f(x_pos - font_size, y_pos_unit - font_size)); //left top
	title.setString("Ranking");
}

void RankingHUD::setGamemode()
{
	gamemode.setFont(font);
	gamemode.setFillColor(sf::Color::White);
	gamemode.setCharacterSize(0.8 * font_size);
	gamemode.setPosition(
		sf::Vector2f(width - 4 * x_pos, y_pos_unit + 0.2 * font_size)); //right top
	if (file_name[6] == '0') gamemode.setString("Easy Mode");
	else if (file_name[6] == '1') gamemode.setString("Normal Mode");
	else if (file_name[6] == '2') gamemode.setString("Hard Mode");
}

void RankingHUD::setExit()
{
	exit.setFont(font);
	exit.setFillColor(sf::Color{ 75, 75, 75, 255 }); //grey
	exit.setCharacterSize(0.4 * font_size);
	exit.setPosition(
		sf::Vector2f(width - 3 * font_size, height - 0.8 * font_size)); //bottom right corner
	exit.setString("[ESC] Exit");
}

void RankingHUD::setNavigation()
{
	navigation.setFont(font);
	navigation.setFillColor(sf::Color{ 75, 75, 75, 255 }); //grey
	navigation.setCharacterSize(0.4 * font_size);
	navigation.setPosition(
		sf::Vector2f(0.4 * font_size, height - 0.8 * font_size)); //bottom left corner
	navigation.setString("[<] Previous\t\t[v] Scrol down\t\t[^] Scroll up\t\t[>] Next");
}

void RankingHUD::run()
{
	draw();
}
