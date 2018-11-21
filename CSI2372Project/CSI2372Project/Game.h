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
    
    int getRound() const { return round; };
    void addPlayer( const Player& );
    Player& getPlayer(Player::Side) const;
    const Card* getPreviousCard() { return previousCard; };
    const Card* getCurrentCard() { return currentCard; };
    void setCurrentCard( const Card* card);
    Card* getCard( const Board::Letter&, const Board::Number&);
    void setCard( const Board::Letter&, const Board::Number&, Card*);
    
    friend std::ostream& operator<<(std::ostream& os, const Game&);
    
protected:
    Board& getBoard() const { return *gameBoard; };
    std::vector<Player> getPlayers() const { return gamePlayers; };
    void reset(); // resets board and sets all players to active
    
private:
    int round;
    const Card * currentCard;
    const Card * previousCard;
    Board *gameBoard;
    std::vector<Player> gamePlayers;
};

#endif
