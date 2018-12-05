//#define TEST_GAME_

#include <iostream>
#include <stdlib.h>

#include "Game.h"

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

void Game::nextRound()
{
    round++;
    currentCard = nullptr;
    previousCard = nullptr;
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

#ifdef TEST_GAME_
    int main()
    {
        Board *gameBoard = new Board(1);
        Game *game = new Game(gameBoard);
        CardDeck *cardDeck = &CardDeck::make_CardDeck();
        
        Player player("Tester");
        player.setSide(Player::Side::top);
        game->addPlayer(player);
        Player gamePlayer = game->getPlayer(Player::Side::top);
        bool isPlayersCorrect = (player.getName() == gamePlayer.getName() && player.getSide() == gamePlayer.getSide());
        
        Card *prevCard = cardDeck->getNext();
        Card *currentCard = cardDeck->getNext();
        game->setCurrentCard(prevCard);
        game->setCurrentCard(currentCard);
        Card gamePrevCard = *game->getPreviousCard();
        Card gameCurrentCard = *game->getCurrentCard();
        //write bool to test this
    
        game->nextRound();
        bool isRoundCorrect = (game->getRound() == 1 && game->getCurrentCard() == nullptr && game->getPreviousCard() == nullptr);
        
        if(isPlayersCorrect && isRoundCorrect)
            std::cout << "Game has passed its tests" << std::endl;
        else
            std::cerr << "Game didnt pass its tests" << std::endl;
    }
#endif
