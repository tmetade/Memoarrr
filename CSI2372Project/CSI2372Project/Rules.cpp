#include "Rules.h"

//Design a class Rules which has the main purpose to check if a selection of a player is valid. 

Rules::Rules(int ruleType)
{
    
}

Rules::~Rules()
{
    
}

bool Rules::isValid(const Game& game)
{
    // returns true is previous and current card match; false otherwise. 
    return true;
}

bool Rules::gameOver(const Game& game)
{
    //returns true if the number of rounds has reached 7
    return true;
}

bool Rules::roundOver(const Game& game)
{
    //  returns true if there is only one active Player left.
    return true;
}
