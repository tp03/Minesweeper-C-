#pragma once
#include "Board.h"


class GameInterface
{
private:
	bool still_playing;
public:
	GameInterface()
	{
		still_playing = true;
	}

	void showBoard(Board board) const;
	bool getPlaying() const;
	void setPlaying(bool b);
};