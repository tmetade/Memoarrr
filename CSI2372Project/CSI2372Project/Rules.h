#ifndef Rules_h
#define Rules_h

#include <stdio.h>

#include "Game.h"

class Rules
{
public:
    Rules(int ruleType);
    ~Rules();
    
    bool isValid(const Game&);
    bool gameOver(const Game&);
    bool roundOver(const Game&);
    const Player& getNextPlayer(const Game&);
};

#endif
