#include "Board.h"

Board::Board()
{
    for(int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (j==0 || j==4 || j==8 || j==12 || j==16 || i==3 || i==4 || i==8 || i==9 || i==13 || i==14 || i==18 || i==19 || i==23 || i==24 || (i==10 &&j==9) || (i==10 &&j==10) ||(i==10 &&j==11) || (i==11 &&j==9) || (i==11 &&j==10) ||(i==11 &&j==11) || (i==12 &&j==9) || (i==12 &&j==10) ||(i==12 &&j==11))
            {
                boardDisplay[i][j] = " ";
            }
            else
            {
                boardDisplay[i][j] = "z";
            }
        }
    }
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

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    for(int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 20; j++)
        {
           os<< board.boardDisplay[i][j] ;
        }
        os<<std::endl;
    }
    return os;
}
