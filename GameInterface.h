#pragma once
#include "Board.h"
#include "Player.h"


class GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	int player_score;
	Board board;

public:
	GameInterface()
	{}

	void showBoard(Board& board, int added_time, bool game_loaded);
	void againLostWindow(Player& p, int level);
	void againWonWindow(Player& p, int level);
	virtual void playGame(Player& p) = 0;
	int getHeight() const;
	int getWidth() const;
	int getMines() const;
	void setWon(bool b);
	bool getWon() const;
	void setLost(bool b);
	bool getLost() const;
	int getScore() const;
	void setScore(int score);

};

class EasyGame : public GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	int player_score;
	Board board;

public:
	EasyGame()
		:GameInterface()
	{
		width = 8;
		height = 8;
		mine_count = 9;

	}

	virtual void playGame(Player& p) override;

};

class MediumGame : public GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	int player_score;
	Board board;

public:
	MediumGame()
		:GameInterface()
	{
		width = 16;
		height = 16;
		mine_count = 40;

	}

	virtual void playGame(Player& p) override;

};

class HardGame : public GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	int player_score;
	Board board;

public:
	HardGame()
		:GameInterface()
	{
		width = 23;
		height = 16;
		mine_count = 60;

	}

	virtual void playGame(Player& p) override;

};

class LoadedGame : public GameInterface
{
private:
	bool has_won;
	bool has_lost;
	int mine_count;
	int height;
	int width;
	int player_score;
	Board board;

public:
	LoadedGame()
		:GameInterface()
	{
		std::ifstream inputFile("saved_board.json");

		if (inputFile.is_open())
		{
			nlohmann::json boardData;
			inputFile >> boardData;
			int k = boardData.size();

			if (k == 64)
			{
				width = 8;
				height = 8;
				mine_count = 9;
			}
			else if (k == 256)
			{
				width = 16;
				height = 16;
				mine_count = 40;
			}
			else
			{
				width = 23;
				height = 16;
				mine_count = 60;
			}
		}

	}

	virtual void playGame(Player& p) override;

};

