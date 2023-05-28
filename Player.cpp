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
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}