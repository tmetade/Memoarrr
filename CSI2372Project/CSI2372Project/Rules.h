#ifndef Rules_h
#define Rules_h

#include <stdio.h>

#include "Game.h"

class Rules
{
public:
    Rules();
    ~Rules();
    
    bool isValid(const Game&);
    bool gameOver(const Game&);
    bool roundOver(const Game&);
};

#endif