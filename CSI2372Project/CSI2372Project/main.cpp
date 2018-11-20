#include <iostream>
#include <stdlib.h>

#include "Board.h"
#include "CardDeck.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"
#include "RewardDeck.h"
#include "Rules.h"

using namespace std;

void printCards(Card* card1, Card* card2, Card* card3)
{
    cout << (*card1)(0) << " " << (*card2)(0) << " " << (*card3)(0) << endl;
    cout << (*card1)(1) << " " << (*card2)(1) << " " << (*card3)(1) << endl;
    cout << (*card1)(2) << " " << (*card2)(2) << " " << (*card3)(2) << endl;
    cout << endl;
}

int main(int argc, const char * argv[])
{
    int gameVersion = 0, nPlayers = 0;
    
    while(gameVersion<1 || gameVersion > 3)
    {
        cout << "Select your game version: " << std::endl;
        cout << "1-Base Game 2-Expert Display Mode 3-Expert Rules Mode ";
        cin >> gameVersion;
    }
    
    while(nPlayers<2 || nPlayers>4)
    {
        cout << "Enter the number of players (2-4): ";
        cin >> nPlayers;
    }
    
    string playerNames[nPlayers];
    string tempPlayerName;
    cout << "Enter the name of the players: ";
    for(int i=0; i<nPlayers; i++)
    {
        std::cin >> tempPlayerName;
        playerNames[i] = tempPlayerName;
    }
    
    //Create the game objects
    Rules gameRules(gameVersion);
    Board *gameBoard = new Board(gameVersion);
    Game *game = new Game(gameBoard);
    for (int i = 0; i<nPlayers; i++)
    {
        Player newPlayer(playerNames[i]);
        newPlayer.setSide((Player::Side)i);
        game->addPlayer(newPlayer);
    }
    
    cout<< *game;
    
    while(gameRules.gameOver(*game))
    {
        gameBoard->reset();
        
        for (int i = 1; i <= nPlayers; i++)
        {
            Player temp = game->getPlayer((Player::Side)i);
            cout << "Displaying Cards for " << temp;
            
            Card* card1;
            Card* card2;
            Card* card3;
            
            switch(temp.getSide())
            {
                case Player::top :
                {
                    card1 = gameBoard->getCard(Board::A, Board::two);
                    card2 = gameBoard->getCard(Board::A, Board::three);
                    card3 = gameBoard->getCard(Board::A, Board::four);
                    printCards(card1, card2, card3);
                    break;
                }
                case Player::bottom :
                {
                    card1 = gameBoard->getCard(Board::E, Board::two);
                    card2 = gameBoard->getCard(Board::E, Board::three);
                    card3 = gameBoard->getCard(Board::E, Board::four);
                    printCards(card1, card2, card3);
                    break;
                }
                case Player::left :
                {
                    card1 = gameBoard->getCard(Board::B, Board::one);
                    card2 = gameBoard->getCard(Board::C, Board::one);
                    card3 = gameBoard->getCard(Board::D, Board::one);
                    printCards(card1, card2, card3);
                    break;
                }
                case Player::right :
                {
                    card1 = gameBoard->getCard(Board::B, Board::five);
                    card2 = gameBoard->getCard(Board::C, Board::five);
                    card3 = gameBoard->getCard(Board::D, Board::five);
                    printCards(card1, card2, card3);
                    break;
                }
            }
        }
        
        while(!gameRules.roundOver(*game))
        {
            std::string cardCoord;
            //Player nextPlayer = gameRules.getNextPlayer(*game);
            cout << "Enter in a card coordinate you would like to reveal: (eg. A2)";
            cin >> cardCoord;
            
            //update Board
            if(!gameRules.isValid(*game))
            {
                //nextPlayer.setActive(false);
            }
            
            cout << *game;
        }
        //remaing active player gets reward
    }
    
    // print players with their number of rubies sorted form least to most rubies
    // print overall winner
    
    return 0;
}
