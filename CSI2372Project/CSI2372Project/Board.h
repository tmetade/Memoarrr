#ifndef Board_h
#define Board_h

#include <stdio.h>

#include "Card.h"
#include "CardDeck.h"

class Board
{
public:
    Board( int gameVersion);
    ~Board();
    
    enum Letter {A, B, C, D, E};
    enum Number {one = 1, two = 2, three = 3, four = 4, five = 5};
    std::string boardDisplay[21];
    
    const bool isFaceUp( const Letter&, const Number&);
    bool turnFaceUp( const Letter&, const Number& );
    bool turnFaceDown( const Letter&, const Number& );
    void reset();
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    
    friend std::ostream& operator<<(std::ostream& os, const Board&);
    
private:
    CardDeck &cardDeck = CardDeck::make_CardDeck();
    Card* cardBoard [5][5];
    bool cardFaceDown[5][5];
    int convertLetterToIndex(const Letter&);
    int convertNumberToIndex(const Number&);
    void reconstructBoard();

};

#endif
