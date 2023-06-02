#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;


class Reader
{
	std::string file_name;

	std::vector <std::string> nicknames;
	std::vector <int> scores;

	void readFromFile();
	void sortLists();

public:
	Reader(std::string f_name);

	std::vector <std::string> returnNicknameList();
	std::vector <int> returnScoreList();
};
