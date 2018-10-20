#ifndef Board_h
#define Board_h

#include <stdio.h>

class Board
{
public:
    Board();
    ~Board();
    
    enum Letter {A,B};
    enum Number {Apple,Banana};
    
    bool isFaceUp( const Letter&, const Number&) const;
    bool turnFaceUp( const Board::Letter&, const Board::Number& );
    bool turnFaceDown( const Board::Letter&, const Board::Number& );
    void reset();
    
};

#endif
