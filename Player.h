#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

class Player {
public:
    Player();
    Player(const std::string& name);

    std::string getName() const;
    int getScore() const;
    void increaseScore(int amount);
    void resetScore();
    void setScore(int amount);
    void saveScore(int difficulty);

private:
    std::string name_;
    int score_;
};
