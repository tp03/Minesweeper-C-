#pragma once

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
		has_mine = false;
		has_flag = false;
		open = false;
	}

	bool IsMine() const;
	bool IsFlag() const;
	bool IsOpen() const;
	int getAdjacentMines() const;
	int getX() const;
	int getY() const;
	void setMine(bool boolean);
	void setFlag(bool boolean);
	void setOpen(bool boolean);
	void setAdjacentMines(int mine_count);

};


class Mine : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	bool has_mine = true;
	bool has_flag = false;
	bool open = true;

public:

	Mine(int x, int y)
		: Cell(x, y)
	{}
};


class Flag : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	bool has_mine = false;
	bool has_flag = true;
	bool open = true;

public:

	Flag(int x, int y, int adjacent_mines)
		: Cell(x, y), adjacent_mines(adjacent_mines)
	{}

};


class Numbered : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	bool has_mine = false;
	bool has_flag = false;
	bool open = true;

public:

	Numbered(int x, int y, int adjacent_mines)
		: Cell(x, y), adjacent_mines(adjacent_mines)
	{}

};

class Closed : public Cell
{
private:

	int x_coordinate;
	int y_coordinate;
	int adjacent_mines;
	bool has_mine = false;
	bool has_flag = false;
	bool open = false;

public:

	Closed(int x, int y)
		: Cell(x, y)
	{}

};