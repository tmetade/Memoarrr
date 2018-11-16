#include "Board.h"

Board::Board()
{
    //the constructor for the board should throw an exception of type NoMoreCards if there are no more cards available to construct the board
}

Board::~Board()
{
    
}

const bool Board::isFaceUp( const Letter& letter, const Number& number)
{

    //returns true if the card at a given position is
    //face up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid
    //Letter and Number combination was given.
    return true;
}

bool Board::turnFaceUp( const Letter& letter, const Number& number )
{
    //    changes the state of the specified card return false
    //if card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number
    //combination was given.
    return true;
}

bool Board::turnFaceDown( const Letter& letter, const Number& number )
{
    //    changes the state of the specified card return
    //false if card was down already. Throws an exception of type OutOfRange if an invalid Letter and
    //Number combination was given.
    return true;
}

void Board::reset()
{
    //changes the state to all cards to be face down
}

Card* Board::getCard( const Letter& letter, const Number& number )
{
    // returns a pointer to the card at a given location. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given
    return NULL;
}

void Board::setCard(const Letter& letter, const Number& number, Card* card)
{
    
}

//A board must be printable with the insertion operator cout << board.
