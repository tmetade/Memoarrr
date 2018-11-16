#ifndef Game_h
#define Game_h

#include <stdio.h>

#include "Board.h"
#include "Card.h"
#include "Player.h"

class Game
{
public:
    Game();
    ~Game();
    
    int getRound(){ return round; };
    void addPlayer( const Player& );
    Player& getPlayer(Player::Side);
    const Card* getPreviousCard();
    const Card* getCurrentCard();
    void setCurrentCard( const Card* card);
    Card* getCard( const Board::Letter&, const Board::Number&);
    void setCard( const Board::Letter&, const Board::Number&, Card*);
    
private:
    int round;
    const Card *currentCard;
};

#endif
