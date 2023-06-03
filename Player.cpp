#include "Player.h"

Player::Player() : score_(0) {}

Player::Player(const std::string& name) : name_(name), score_(0) {}

std::string Player::getName() const {
    return name_;
}

int Player::getScore() const {
    return score_;
}

void Player::increaseScore(int amount) {
    score_ += amount;
}

void Player::resetScore() {
    score_ = 0;
}

void Player::setScore(int amount) {
    score_ = amount;
}

void Player::saveScore(int difficulty) {
    using json = nlohmann::json;
    std::string fileName = "scores" + std::to_string(difficulty) + ".txt";
    std::ofstream outputFile(fileName, std::ios::app);

    if (outputFile.is_open()) {
        json playerData;
        playerData["name"] = getName();
        playerData["score"] = getScore();

        outputFile << playerData.dump(4);
        outputFile.close();
        std::cout << "Player result saved to " << fileName << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}

void Player::fixedSaveScore(int difficulty) {
    using json = nlohmann::json;

    std::string fileName = "scores" + std::to_string(difficulty) + ".txt";
    std::vector<std::pair<std::string, int>> player_data;
    std::ifstream inputFile(fileName);

    if (inputFile.good())
    {
        try
        {
            json data = json::parse(inputFile);
            inputFile.close();

            for (int i = 0; i < data.size(); ++i)
            {
                player_data.push_back({ data[i]["name"], data[i]["score"] });
            }
        }
        catch (const json::parse_error& e)
        {
            inputFile.close();
        }
    }

    std::ofstream outputFile(fileName, std::ios::out);
    json allPlayersData;

    if (outputFile.is_open()) {
        player_data.push_back({ getName(), getScore() });

        json playerData;
        for (int i = 0; i < player_data.size(); i++)
        {
            playerData["name"] = player_data[i].first;
            playerData["score"] = player_data[i].second;
            allPlayersData.push_back(playerData);
        }

        outputFile << allPlayersData.dump(4);
        outputFile.close();
        std::cout << "Player result saved to " << fileName << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}