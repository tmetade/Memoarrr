#include "Player.h"
#include "Rules.h"

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
    nRubies += reward;
}

std::string Player::getSideString() const
{
    return sideString[playerSide];
}

std::ostream& operator<<(std::ostream& os, const Player &p)
{
    if(!p.displayEndGame)
    {
        
        std::string activeText;
        if(p.isActive())
            activeText = "active";
        else
            activeText = "inactive";
        
        
        os << p.getName() << ": " << p.getSideString() << " (" << activeText << ")" << std::endl;
    }
    else
        os << p.getName() << ": " << p.getNRubies() << " rubies";
    return os;
}
