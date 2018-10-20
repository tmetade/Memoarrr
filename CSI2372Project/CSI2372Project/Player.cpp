#include "Player.h"

Player::Player(std::string playerName)
{
    name = playerName;
}

Player::~Player()
{
    
}

void Player::addReward(const Reward& reward)
{
    
}

void Player::setDisplayMode(bool endOfGame)
{
    
}

//Dont know why but this prints memory address
std::ostream& operator<<(std::ostream& os, const Player p) {
    os << "I'm in the class, msg=" << std::endl;
    return os;
}
