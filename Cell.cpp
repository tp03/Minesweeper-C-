#include "Cell.h"
#include <iostream>
#include <..\SFML\Graphics.hpp>


bool Cell::isMine() const
{
	return has_mine;
}

bool Cell::isFlag() const
{
	return has_flag;
}

bool Cell::isOpen() const
{
	return open;
}

int Cell::getAdjacentMines() const
{
	return adjacent_mines;
}

int Cell::getX() const
{
	return x_coordinate;
}

int Cell::getY() const
{
	return y_coordinate;
}

void Cell::setMine(bool boolean)
{
	has_mine = boolean;
}

void Cell::setFlag(bool boolean)
{
	has_flag = boolean;
}

void Cell::setOpen(bool boolean)
{
	open = boolean;

}

void Cell::setAdjacentMines(int mine_count)
{
	adjacent_mines = mine_count;
}

sf::Sprite Mine::reveal()
{

	mine_texture = new sf::Texture;
	mine_texture->loadFromFile("mine.png");
	mine_sprite.setTexture(*mine_texture);
	sf::Sprite sprite = mine_sprite;
	int x = 100 * getX();
	int y = 100 * getY();
	sprite.setPosition(x, y);

	return sprite;

}

sf::Sprite Flag::reveal()
{

	flag_texture = new sf::Texture;
	flag_texture->loadFromFile("flag.png");
	flag_sprite.setTexture(*flag_texture);
	sf::Sprite sprite = flag_sprite;
	int x = 100 * getX();
	int y = 100 * getY();
	sprite.setPosition(x, y);

	return sprite;
}

sf::Sprite Numbered::reveal()
{

	numbered_texture = new sf::Texture;
	if (getAdjacentMines() == 0)
	{
		numbered_texture->loadFromFile("0.png");
	}

	else if (getAdjacentMines() == 1)
	{
		numbered_texture->loadFromFile("1.png");
	}

	else if (getAdjacentMines() == 2)
	{
		numbered_texture->loadFromFile("2.png");
	}

	else if (getAdjacentMines() == 3)
	{
		numbered_texture->loadFromFile("3.png");
	}

	else if (getAdjacentMines() == 4)
	{
		numbered_texture->loadFromFile("4.png");
	}

	else if (getAdjacentMines() == 5)
	{
		numbered_texture->loadFromFile("5.png");
	}

	else if (getAdjacentMines() == 6)
	{
		numbered_texture->loadFromFile("6.png");
	}

	else if (getAdjacentMines() == 7)
	{
		numbered_texture->loadFromFile("7.png");
	}
	else
	{
		numbered_texture->loadFromFile("8.png");
	}
	numbered_sprite.setTexture(*numbered_texture);
	sf::Sprite sprite = numbered_sprite;
	int x = 100 * getX();
	int y = 100 * getY();
	sprite.setPosition(x, y);

	return sprite;
}

sf::Sprite Closed::reveal()
{

	closed_texture = new sf::Texture;
	closed_texture->loadFromFile("closed.png");
	closed_sprite.setTexture(*closed_texture);
	sf::Sprite sprite = closed_sprite;
	int x = 100 * getX();
	int y = 100 * getY();
	sprite.setPosition(x, y);

	return sprite;
}

