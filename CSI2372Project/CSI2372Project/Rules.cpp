#include "Rules.h"

//Design a class Rules which has the main purpose to check if a selection of a player is valid. 

Rules::Rules(int ruleType)
{
    
}

Rules::~Rules()
{
    
}

bool Rules::isValid(const Game& game) const
{
    //no idea how to do this LOL
    
    //return (*game.getCurrentCard())(2) == (game.getPreviousCard())(2);
    return true;
}

bool Rules::gameOver(const Game& game)
{
    return game.getRound() == 7;
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
