//#define TEST_PLAYER_

#include "Player.h"
#include "RewardDeck.h"
#include "Rules.h"

Player::Player(std::string name)
{
    playerName = name;
    active = true;
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

#ifdef TEST_PLAYER_
int main()
{
    std::string playerName = "player1";
    Player player1(playerName);
    RewardDeck *rewardDeck = &RewardDeck::make_RewardDeck();
    
    bool isPlayerName = playerName == player1.getName();
    
    player1.setActive(false);
    bool isPlayerOut = !player1.isActive();
    
    //RewardDeck is not shuffled so we know the next card will be 4
    Reward *reward = rewardDeck->getNext();
    player1.addReward(*reward);
    bool isReward = player1.getNRubies() == 4;
    
    Player::Side playerSide = Player::Side::top;
    player1.setSide(playerSide);
    bool isSide = player1.getSide() == playerSide;
    
    if(isPlayerName && isPlayerOut && isReward && isSide)
        std::cout << "Player has passed its tests" << std::endl;
    else
        std::cerr << "Player didnt pass its tests" << std::endl;
}
#endif
