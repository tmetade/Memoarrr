//#define TEST_RULES_

#include "Rules.h"

//Design a class Rules which has the main purpose to check if a selection of a player is valid. 

Rules::Rules(int ruleType)
{
    isHardMode = ruleType == 3 || ruleType == 4;
}

Rules::~Rules()
{
    
}

bool Rules::isBlocked(const Game& game, Card * card){
    const Card * currCard = game.getCurrentCard();
    bool sameFace = currCard->face[1] == (*card)(1);
    
    if(isHardMode){
        if(sameFace){
            return true;
        } else {
            blockedCard = "";
        }
    }
    
    return false;
}

bool Rules::isValid(const Game& game) const
{
    const Card * prevCard = game.getPreviousCard();
    const Card * currCard = game.getCurrentCard();
    
    //if first card flipped
    //OR curr card background matches prev card background
    //OR curr card face matches prev card face
    //OR is NOT BLOCKED
    if(prevCard == nullptr || prevCard->face[0] == currCard->face[0] ||
       prevCard->face[1].at(1) == currCard->face[1].at(1)){
        return true;
    }
    
    return false;
}

bool Rules::gameOver(const Game& game)
{
    return game.getRound() == 3;
}

bool Rules::roundOver(const Game& game)
{
    Player *currentPlayer;
    int numOfActivePlayers = 0;
    
    for(int  i = 0; i < 4; i++)
    {
        currentPlayer = &game.getPlayer((Player::Side)i);
        
        if(currentPlayer != nullptr && currentPlayer->isActive())
        {
            numOfActivePlayers++;
        }
    }
    
    return numOfActivePlayers == 1;
}

const Player& Rules::getNextPlayer(const Game& game)
{
    int playerSide = currentPlayerSide;
    
    const Player *currentPlayer = nullptr;
    currentPlayer = &game.getPlayer((Player::Side)playerSide);
    
    while (currentPlayer == nullptr)
    {
        playerSide++;
        playerSide = playerSide%4;
        currentPlayer = &game.getPlayer((Player::Side)playerSide);
    }
    playerSide++;
    playerSide = playerSide%4;

    currentPlayerSide = (Player::Side)playerSide;
    
    return *currentPlayer;
}

#if TEST_RULES_

#else

#endif
