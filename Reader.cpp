#include "Reader.h"


Reader::Reader(std::string f_name)
	: file_name(f_name)
{
	readFromFile();
	sortLists();
}

void Reader::readFromFile()
{
	std::ifstream file(file_name);

	if (file.good())
	{
		try
		{
			json data = json::parse(file);

			for (int i = 0; i < data.size(); ++i)
			{
				nicknames.push_back(data[i]["name"]);
				scores.push_back(data[i]["score"]);
			}
		}
		catch (const json::parse_error& e)
		{
			file.close();
		}
	}
}

void Reader::sortLists()
{
	for (int i = 0; i < int(nicknames.size() - 1); ++i)
	{
		int max_index = i;
		for (int j = i + 1; j < nicknames.size(); j++)
		{
			if (scores[j] > scores[max_index]) {
				max_index = j;
			}
		}
		std::swap(nicknames[i], nicknames[max_index]);
		std::swap(scores[i], scores[max_index]);
	}
}


std::vector <std::string> Reader::returnNicknameList()
{
	return nicknames;
}

std::vector <int> Reader::returnScoreList()
{
	return scores;
}
