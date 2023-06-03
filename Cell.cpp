#include "Cell.h"


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

void Mine::setSprite()
{

	mine_texture = new sf::Texture;
	mine_texture->loadFromFile("textures/mine.png");
	mine_sprite.setTexture(*mine_texture);
	int x = 100 * getX();
	int y = 100 * getY();
	mine_sprite.setPosition(x, y);
}

sf::Sprite Mine::reveal()
{

	return mine_sprite;

}

void Flag::setSprite()
{

	flag_texture = new sf::Texture;
	flag_texture->loadFromFile("textures/flag.png");
	flag_sprite.setTexture(*flag_texture);
	int x = 100 * getX();
	int y = 100 * getY();
	flag_sprite.setPosition(x, y);
}

sf::Sprite Flag::reveal()
{

	return flag_sprite;
}

void Numbered::setSprite()
{

	numbered_texture = new sf::Texture;
	if (getAdjacentMines() == 0)
	{
		numbered_texture->loadFromFile("textures/0.png");
	}

	else if (getAdjacentMines() == 1)
	{
		numbered_texture->loadFromFile("textures/1.png");
	}

	else if (getAdjacentMines() == 2)
	{
		numbered_texture->loadFromFile("textures/2.png");
	}

	else if (getAdjacentMines() == 3)
	{
		numbered_texture->loadFromFile("textures/3.png");
	}

	else if (getAdjacentMines() == 4)
	{
		numbered_texture->loadFromFile("textures/4.png");
	}

	else if (getAdjacentMines() == 5)
	{
		numbered_texture->loadFromFile("textures/5.png");
	}

	else if (getAdjacentMines() == 6)
	{
		numbered_texture->loadFromFile("textures/6.png");
	}

	else if (getAdjacentMines() == 7)
	{
		numbered_texture->loadFromFile("textures/7.png");
	}
	else
	{
		numbered_texture->loadFromFile("textures/8.png");
	}
	numbered_sprite.setTexture(*numbered_texture);
	int x = 100 * getX();
	int y = 100 * getY();
	numbered_sprite.setPosition(x, y);
}

sf::Sprite Numbered::reveal()
{

	return numbered_sprite;

}

void Closed::setSprite()
{

	closed_texture = new sf::Texture;
	closed_texture->loadFromFile("textures/closed.png");
	closed_sprite.setTexture(*closed_texture);
	int x = 100 * getX();
	int y = 100 * getY();
	closed_sprite.setPosition(x, y);
}

sf::Sprite Closed::reveal()
{
	return closed_sprite;
}

bool Cell::isSpriteClicked(const sf::Vector2i& mousePosition)
{

	sf::Sprite spr = reveal();
	sf::FloatRect sprite_bounds = spr.getGlobalBounds();

	if (sprite_bounds.contains(mousePosition.x, mousePosition.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
