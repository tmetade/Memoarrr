#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <vector>

#include "Board.h"
#include "Card.h"
#include "Player.h"

class Game
{
public:
    Game(Board *board);
    ~Game();
    
    int getRound(){ return round; };
    void addPlayer( const Player& );
    Player& getPlayer(Player::Side);
    const Card* getPreviousCard();
    const Card* getCurrentCard();
    void setCurrentCard( const Card* card);
    Card* getCard( const Board::Letter&, const Board::Number&);
    void setCard( const Board::Letter&, const Board::Number&, Card*);
    Board& getBoard() const { return *gameBoard; };
    std::vector<Player> getPlayers() const { return gamePlayers; };
    
    friend std::ostream& operator<<(std::ostream& os, const Game&);
    
private:
    int round;
    const Card *currentCard;
    Board *gameBoard;
    std::vector<Player> gamePlayers;
};

#endif
