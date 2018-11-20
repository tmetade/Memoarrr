#include "Board.h"

Board::Board(int gameVersion)
{
    bool displayCoordinates = true;
    
    if (gameVersion == 1)
        displayBoard();
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

void Board::displayBoard()
{
    for(int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (j==0 || j==1 || j==5 || j==9 || j==13 || j==17 || i==3 || i==4 || i==8 || i==9 || i==13 || i==14 || i==18 || i==19 || i==23 || i==24 || i==25 || (i==10 &&j==10) || (i==10 &&j==11) ||(i==10 &&j==12) || (i==11 &&j==10) || (i==11 &&j==11) ||(i==11 &&j==12) || (i==12 &&j==10) || (i==12 &&j==11) ||(i==12 &&j==12))
            {
                boardDisplay[i][j] = " ";
            }
            else
            {
                boardDisplay[i][j] = "z";
            }
        }
    }
    
    boardDisplay[25][2] = "1";
    boardDisplay[25][6] = "2";
    boardDisplay[25][10] = "3";
    boardDisplay[25][14] = "4";
    boardDisplay[25][18] = "5";
    boardDisplay[1][0] = "A";
    boardDisplay[6][0] = "B";
    boardDisplay[11][0] = "C";
    boardDisplay[16][0] = "D";
    boardDisplay[21][0] = "E";
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
