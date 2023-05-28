#pragma once
#include "Board.h"


class GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	Board board;

public:
	GameInterface()
	{}

	void showBoard(Board board) const;
	virtual void playGame() = 0;
	int getHeight() const;
	int getWidth() const;
	int getMines() const;
	void setWon(bool b);
	bool getWon() const;
	void setLost(bool b);
	bool getLost() const;
	void checkIfWon();
	void checkIfLost();
};

class EasyGame : public GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	Board board;

public:
	EasyGame()
		:GameInterface()
	{
		width = 8;
		height = 8;
		mine_count = 9;

	}

	virtual void playGame() override;

};