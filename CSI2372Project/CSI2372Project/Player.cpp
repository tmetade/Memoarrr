#include "Player.h"

Player::Player(std::string name)
{
    playerName = name;
    active = true;
    outputString += playerName + " : " + " (active)";
}

Player::~Player()
{
    
}

void Player::addReward(const Reward& reward)
{
    
}

void Player::setDisplayMode(bool endOfGame)
{
    if(endOfGame)
    {
        
    }
}

std::ostream& operator<<(std::ostream& os, const Player &p)
{
    os << p.outputString << std::endl;
    return os;
}
