#include "Player.h"

Player::Player(std::string name, Position &pos)
{
    playerName = name;
    playerPos = pos;
    active = true;
    outputString += playerName + " : " + " (active)";
}

Player::~Player()
{
    
}

void addReward(const Reward& reward);
void setDisplayMode(bool endOfGame);


void Player::addReward(const Reward& reward)
{
    nRubies += reward.getReward();
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
