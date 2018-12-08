#ifndef Rules_h
#define Rules_h

#include <stdio.h>

#include "Game.h"

class Rules
{
public:
    Rules(int ruleType);
    
    bool isValid(const Game&) const;
    bool gameOver(const Game&);
    bool roundOver(const Game&);
    const Player& getNextPlayer(const Game&);

private:
    Player::Side currentPlayerSide = Player::top;
    bool isHardMode;
};
#endif
