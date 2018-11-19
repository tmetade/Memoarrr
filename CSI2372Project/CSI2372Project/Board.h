#ifndef Board_h
#define Board_h

#include <stdio.h>

#include "Card.h"

class Board
{
public:
    Board( int gameVersion);
    ~Board();
    
    enum Letter {A,B};
    enum Number {Apple,Banana};
    std::string boardDisplay [26][21];
    
    const bool isFaceUp( const Letter&, const Number&);
    bool turnFaceUp( const Letter&, const Number& );
    bool turnFaceDown( const Letter&, const Number& );
    void reset();
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    
    friend std::ostream& operator<<(std::ostream& os, const Board&);
};

#endif
