#include "Game.h"

//Design a class Game that encapsulates the current state of the game and it will have a class variable of type Board. It is responsible to print the current state of the game. 

Game::Game(Board *board)
: round(0)
, currentCard()
//, currentPlayer()
{
    
}

Game::~Game()
{
    
}

void Game::addPlayer( const Player& )
{
    //which adds a Player to this game
}

const Card* Game::getPreviousCard()
{
    return NULL;
}

const Card* Game::getCurrentCard()
{
    return NULL;
}

void Game::setCurrentCard(const Card* card)
{
    currentCard = card;
}

Card* Game::getCard(const Board::Letter& letter, const Board::Number& number)
{
    //which calls the corresponding method in Board
    return nullptr;
}

void Game::setCard(const Board::Letter& letter, const Board::Number& number, Card* card)
{
    //which calls the corresponding method in Board
}

//A game must be printable with the insertion operator cout << game. It should display the board and all players. 
