#ifndef Game_h
#define Game_h

#include <stdio.h>
#include "Player.h"
#include "Card.h"

class Game
{
public:
    Game();
    ~Game();
    
    int getRound(){ return round; };
    void addPlayer( const Player& );
    Player& getPlayer() { return currentPlayer; };
    const Card* getPreviousCard();
    const Card* getCurrentCard();
    void setCurrentCard( const Card* card);
private:
    int round;
    Player currentPlayer;
    const Card *currentCard;
};

#endif
