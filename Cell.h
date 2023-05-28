#pragma once
#include <..\SFML\Graphics.hpp>

class Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	bool has_mine;
	bool has_flag;
	bool open;

public:

	Cell(int x, int y)
	{
		x_coordinate = x;
		y_coordinate = y;

	}

	bool isMine() const;
	bool isFlag() const;
	bool isOpen() const;
	int getAdjacentMines() const;
	int getX() const;
	int getY() const;
	void setMine(bool boolean);
	void setFlag(bool boolean);
	void setOpen(bool boolean);
	bool isSpriteClicked(sf::Vector2i mousePosition);
	void setAdjacentMines(int mine_count);
	virtual void setSprite() = 0;
	virtual sf::Sprite reveal() = 0;

};


class Mine : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	sf::Texture* mine_texture;
	sf::Sprite mine_sprite;
	bool has_mine;
	bool has_flag;
	bool open;

public:

	Mine(int x, int y)
		: Cell(x, y)
	{
		setMine(true);
		setFlag(false);
		setOpen(true);
		setSprite();
	}

	void setSprite() override;
	sf::Sprite reveal() override;
};


class Flag : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	sf::Texture* flag_texture;
	sf::Sprite flag_sprite;
	int adjacent_mines;
	bool has_mine;
	bool has_flag;
	bool open;

public:

	Flag(int x, int y, int adjacent_mines, bool mine)
		: Cell(x, y)
	{
		setAdjacentMines(adjacent_mines);
		setMine(mine);
		setFlag(true);
		setOpen(true);
		setSprite();

	}

	void setSprite() override;
	sf::Sprite reveal() override;

};


class Numbered : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	sf::Texture* numbered_texture;
	sf::Sprite numbered_sprite;
	bool has_mine;
	bool has_flag;
	bool open;

public:

	Numbered(int x, int y, int adjacent_mines)
		: Cell(x, y)
	{
		setAdjacentMines(adjacent_mines);
		setMine(false);
		setFlag(false);
		setOpen(true);
		setSprite();

	}

	void setSprite() override;
	sf::Sprite reveal() override;

};

class Closed : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	sf::Texture* closed_texture;
	sf::Sprite closed_sprite;
	bool has_mine;
	bool has_flag;
	bool open;

public:

	Closed(int x, int y)
		: Cell(x, y)
	{
		setMine(false);
		setFlag(false);
		setOpen(false);
		setSprite();
	}

	void setSprite() override;
	sf::Sprite reveal() override;
};
