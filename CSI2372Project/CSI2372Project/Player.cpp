#include "Player.h"

Player::Player(std::string name)
{
    playerName = name;
    active = true;
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

std::string Player::getSideString() const
{
    return sideString[playerSide];
}

std::ostream& operator<<(std::ostream& os, const Player &p)
{
    os << std::boolalpha;
    std::string activeText;
    if(p.isActive())
        activeText = "active";
    else
        activeText = "inactive";
    
    
    os << "Player "+ p.getName() + ": " + p.getSideString() + " (" + activeText + ")" << std::endl;
    return os;
}
