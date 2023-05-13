#include "Cell.h"
#include <iostream>


bool Cell::IsMine() const
{
	if (has_mine)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cell::IsFlag() const
{
	if (has_flag)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cell::IsOpen() const
{
	if (open)
	{
		return true;
	}
	else
	{
		return false;
	}
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

