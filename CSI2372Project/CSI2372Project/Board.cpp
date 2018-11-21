#include "Board.h"

struct NoMoreCards : public std::exception
{
    const char * display () const throw ()
    {
        return "No More Cards";
    }
};

Board::Board(int gameVersion)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(!cardDeck.isEmpty()){
                if(i == 2 && j == 2){
                    cardBoard[i][j] = nullptr;
                    cardFaceDown[i][j] = NULL;
                } else {
                    cardBoard[i][j] = cardDeck.getNext();
                    cardFaceDown[i][j] = true;
                }
            } else
                throw NoMoreCards();
        }
    }
    
    if (gameVersion == 1)
        displayBoard();
    
}

Board::~Board()
{
    
}

const bool Board::isFaceUp( const Letter& letter, const Number& number)
{
    //TODO: Throws an exception of type OutOfRange if an invalid
    int row = letter;
    int col = number - 1;
    
    return !cardFaceDown[row][col];
}

bool Board::turnFaceUp( const Letter& letter, const Number& number )
{
    //TODO: Throws an exception of type OutOfRange if an invalid Letter and Number
    
    int row = letter;
    int col = number - 1;
    
    if(!cardFaceDown[row][col])
        return false;
    else
    {
        std::cout<<"turn me";
        cardFaceDown[row][col] = false;
        return true;
    }
}

bool Board::turnFaceDown( const Letter& letter, const Number& number )
{
    //TODO Throws an exception of type OutOfRange if an invalid Letter and

    int row = letter;
    int col = number - 1;
    
    if(cardFaceDown[row][col]){
        return false;
    } else {
        cardFaceDown[row][col] = true;
        return true;
    }
}

void Board::reset()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 2 && j == 2){
                cardFaceDown[i][j] = NULL;
            } else {
                cardFaceDown[i][j] = true;
            }
        }
    }
}

Card* Board::getCard( const Letter& letter, const Number& number )
{
    
    // returns a pointer to the card at a given location. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given
    return cardBoard[letter][number-1];
}

void Board::setCard(const Letter& letter, const Number& number, Card* card)
{
    
}

void constructDisplayFromCards(){
    
}

void Board::displayBoard()
{
    int boardRow = 0;
    std::string rowText;
    
    for(int row = 0; row < 5; row++)
    {
        for(int rowLoop = 0; rowLoop < 3; rowLoop++)
        {
            if(rowLoop == 0 || rowLoop == 2)
            {
                rowText = "  ";
            }
            else
            {
                switch(row)
                {
                    case 0:
                        rowText = "A ";
                        break;
                    case 1:
                        rowText = "B ";
                        break;
                    case 2:
                        rowText = "C ";
                        break;
                    case 3:
                        rowText = "D ";
                        break;
                    case 4:
                        rowText = "E ";
                        break;
                }
            }
            
            for(int col = 0; col < 5; col++)
            {
                if(cardBoard[row][col] != NULL)
                {
                    if(!cardFaceDown[row][col])
                    {
                        rowText += (*cardBoard[row][col])(rowLoop);
                    }
                    else
                    {
                        rowText += "zzz";
                    }
                }
                else
                {
                    rowText += "   ";
                }
                rowText += " ";
            }
            boardRow++;
            boardDisplay[boardRow] = rowText;
        }
        boardRow++;
        rowText = "";
        for(int blankSpaces = 0; blankSpaces < 21; blankSpaces++)
        {
            rowText += " ";
        }
        boardDisplay[boardRow] = rowText;
    }
    rowText = "";

    for(int bottomNavigation = 0; bottomNavigation < 21; bottomNavigation++)
    {
        switch (bottomNavigation) {
            case 3:
                rowText += "1";
                break;
            case 7:
                rowText += "2";
                break;
            case 11:
                rowText += "3";
                break;
            case 15:
                rowText += "4";
                break;
            case 19:
                rowText += "5";
                break;
            default:
                rowText += " ";
                break;
        }
    }
    
    boardDisplay[boardRow] = rowText;
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    for(int i = 0; i < 21; i++)
    {
        os << board.boardDisplay[i];
        os << std::endl;
    }
    return os;
}
