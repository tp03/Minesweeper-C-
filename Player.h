#include <string>

class Player {
public:
    Player();
    Player(const std::string& name);

    std::string getName() const;
    int getScore() const;
    void increaseScore(int amount);
    void resetScore();

private:
    std::string name_;
    int score_;
};
