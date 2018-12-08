//#define TEST_BOARD_

#include "Board.h"
#include <vector>

struct NoMoreCards : public std::exception
{
    const char * display () const throw ()
    {
        return "No More Cards";
    }
};

Board::Board(int gameVersion)
: gameVersion(gameVersion)
{
    cardDeck.shuffle();
    
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
    
    drawBoard();
    
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
        cardFaceDown[row][col] = false;
        drawBoard();
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
        drawBoard();
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
    drawBoard();
}

Card* Board::getCard( const Letter& letter, const Number& number )
{
    return cardBoard[letter][number-1];
}

void Board::setCard(const Letter& letter, const Number& number, Card* card)
{
    cardBoard[letter][number-1] = card;
}

void Board::drawBoard()
{
    //Generic Rules
    if(gameVersion == 1 || gameVersion == 3){
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
        
    } else if (gameVersion == 2 || gameVersion == 4){ //Expert Display Mode
        std::string cardsRevealed = "";
        std::vector<Card*> cardsFacingUp;
        std::string letters [5] = {"A", "B", "C", "D", "E"};
        std::string numbers [5] = {"1", "2", "3", "4", "5"};
        
        for(int row = 0; row < 5; row++){
            for(int col = 0; col < 5; col++){
                if(!cardFaceDown[row][col] && !(row == 2 && col == 2)){
                    
                    cardsFacingUp.push_back(cardBoard[row][col]);
                    cardsRevealed += (letters[row] + numbers[col] + "  ");
                }
            }
        }
        
        if(cardsFacingUp.size() > 0){
            std::string rowText;
            
            for(int currentRow = 0; currentRow < 3; currentRow++){
                rowText = "";
                for(int cardNum = 0; cardNum < cardsFacingUp.size(); cardNum++){
                    rowText += (*cardsFacingUp.at(cardNum))(currentRow);
                    rowText += " ";
                }
                boardDisplay[currentRow] = rowText;
            }
            
            //blank row
            rowText = "";
            for(int blankSpaces = 0; blankSpaces < 21; blankSpaces++)
            {
                rowText += " ";
            }
            
            boardDisplay[4] = cardsRevealed;
        }
    }
    
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    if(board.gameVersion == 1 || board.gameVersion == 3){
        for(int i = 0; i < 21; i++)
        {
            os << board.boardDisplay[i];
            os << std::endl;
        }
    } else if (board.gameVersion == 2 || board.gameVersion == 4){
        for(int i = 0; i < 5; i++)
        {
            os << board.boardDisplay[i];
            os << std::endl;
        }
    }

    return os;
}

#ifdef TEST_BOARD_
int main()
{
    Board *gameBoard = new Board(1);
    CardDeck *cardDeck = &CardDeck::make_CardDeck();
    
    gameBoard->turnFaceUp(Board::Letter::A, Board::Number::one);
    bool isCardFaceUp = gameBoard->isFaceUp(Board::Letter::A, Board::Number::one);
    
    gameBoard->turnFaceDown(Board::Letter::A, Board::Number::one);
    bool isCardFaceDown = !gameBoard->isFaceUp(Board::Letter::A, Board::Number::one);
    
    //flip card over then reset to see if the card has been flipped over
    gameBoard->turnFaceUp(Board::Letter::A, Board::Number::one);
    gameBoard->reset();
    bool isBoardReset = !gameBoard->isFaceUp(Board::Letter::A, Board::Number::one);
    
    Card *card = cardDeck->getNext();
    gameBoard->setCard(Board::Letter::A, Board::Number::one, card);
    bool isCard = gameBoard->getCard(Board::Letter::A, Board::Number::one) == card;
    
    if(isCardFaceUp && isCardFaceDown && isBoardReset && isCard)
        std::cout << "Board has passed its tests" << std::endl;
    else
        std::cerr << "Board didnt pass its tests" << std::endl;
}
#endif
