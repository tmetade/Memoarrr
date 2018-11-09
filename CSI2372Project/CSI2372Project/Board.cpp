#include "Board.h"
#include "Card.h"
#include <vector>

Board::Board()
{
    
    
}

Board::~Board()
{
    
}

const bool isFaceUp( const Board::Letter&, const Board::Number&)
{

    //returns true if the card at a given position is
    //face up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid
    //Letter and Number combination was given.
    return true;
}

bool turnFaceUp( const Board::Letter&, const Board::Number& )
{
    //    changes the state of the specified card return false
    //if card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number
    //combination was given.
    return true;
}

bool turnFaceDown( const Board::Letter&, const Board::Number& )
{
    //    changes the state of the specified card return
    //false if card was down already. Throws an exception of type OutOfRange if an invalid Letter and
    //Number combination was given.
    return true;
}

void reset()
{
    //changes the state to all cards to be face down
}

//A board must be printable with the insertion operator cout << board.
