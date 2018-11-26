#include "Game.h"

//Design a class Game that encapsulates the current state of the game and it will have a class variable of type Board. It is responsible to print the current state of the game. 

Game::Game(Board *board)
: round(0)
, numPlayers(0)
, currentCard()
, gameBoard(board)
{

}

Game::~Game()
{
    
}

void Game::addPlayer( const Player& player)
{
    gamePlayers.push_back(player);
    numPlayers++;
}

Player& Game::getPlayer (Player::Side side) const
{
    Player *ptr = nullptr;
    Player &ref = *ptr;
    
    if(side > numPlayers-1)
    {
        return ref;
    }
    
    return const_cast<Player&>(gamePlayers.at(side));
}

void Game::setCurrentCard(const Card* card)
{
    if(currentCard != nullptr){
        previousCard = currentCard;
    }
    
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

std::ostream& operator<<(std::ostream& os, const Game &game)
{
    std::vector<Player> tempVec = game.getPlayers();
    for (std::vector<Player>::iterator it = tempVec.begin(); it != tempVec.end(); ++it)
    {
        os << *it;
    }
    os << game.getBoard() <<std::endl;
    return os;
}
