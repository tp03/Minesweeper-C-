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
