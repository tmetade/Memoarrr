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
    if(endOfGame)
    {
        
    }
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
        activeText = "true";
    else
        activeText = "false";
    
    
    os << p.getName() + " : " + p.getSideString() + " (" + activeText + ")" << std::endl;
    return os;
}
