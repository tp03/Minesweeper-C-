#pragma once
#include "Board.h"


class GameInterface
{
private:
	int difficulty_level;
public:
	GameInterface(int difficulty = 0)
	{
		difficulty_level = difficulty;
	}

	int getDifficultyLevel() const;
	void showBoard(Board board) const;
};