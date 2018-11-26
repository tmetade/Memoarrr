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

// prints 3 cards side by side
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
    RewardDeck *rewardDeck = &RewardDeck::make_RewardDeck();
    
    for (int i = 0; i<nPlayers; i++)
    {
        Player newPlayer(playerNames[i]);
        newPlayer.setSide((Player::Side)i);
        game->addPlayer(newPlayer);
    }
    
    //prints the players and the board
    cout << *game;
    
    while(!gameRules.gameOver(*game))
    {
        //reset the game for a new round
        gameBoard->reset();
        
        for (int i = 0; i < nPlayers; i++)
        {
            game->getPlayer((Player::Side)i).setActive(true);
            Player temp = game->getPlayer((Player::Side)i);
            
            //displaying the 3 cards infront of each player
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
            std::string cardCoord = "D8";
            
            //get next active player
            Player currentPlayer = gameRules.getNextPlayer(*game);
            cout << currentPlayer;
            
            //assuming we are given the correct coordinates
            cout << "Enter in a card coordinate you would like to reveal: (eg. A2)";
            cin >> cardCoord;
            
            Board::Letter letterSelection;
            Board::Number numberSelection;
            
            switch(cardCoord.at(0))
            {
                case 'A' :
                {
                    letterSelection = Board::A;
                    break;
                }
                case 'B' :
                {
                    letterSelection = Board::B;
                    break;
                }
                case 'C' :
                {
                    letterSelection = Board::C;
                    break;
                }
                case 'D' :
                {
                    letterSelection = Board::D;
                    break;
                }
                case 'E' :
                {
                    letterSelection = Board::E;
                    break;
                }
            }
            
            switch(cardCoord.at(1))
            {
                case '1' :
                {
                    numberSelection = Board::one;
                    break;
                }
                case '2' :
                {
                    numberSelection = Board::two;
                    break;
                }
                case '3' :
                {
                    numberSelection = Board::three;
                    break;
                }
                case '4' :
                {
                    numberSelection = Board::four;
                    break;
                }
                case '5' :
                {
                    numberSelection = Board::five;
                    break;
                }
            }
            
            //might want to ask user to add a new coordinate
            if(gameBoard->turnFaceUp(letterSelection, numberSelection))
                game->setCurrentCard(gameBoard->getCard(letterSelection, numberSelection));
            
            //update Board
            if(!gameRules.isValid(*game))
            {
                cout << currentPlayer.getName() << " has guessed incorrectly! They're now inactive." << std::endl;
                game->getPlayer(currentPlayer.getSide()).setActive(false);
            }
            cout << *game;
        }
        cout << "REWARD ALL THE WINNERS FOR THE ROUND" << endl;
        for(int i = 0; i<nPlayers; i++)
        {
            Player lastPlayer = game->getPlayer((Player::Side)i);
            Reward *playerReward = rewardDeck->getNext();
            if(lastPlayer.isActive())
                lastPlayer.addReward(*playerReward);
        }
        game->nextRound();
        cout << "Next Round Starting!" <<endl;
    }
    
    // print players with their number of rubies sorted form least to most rubies
    // print overall winner
    
    cout << "GAME OVER!" << std::endl;
    
    return 0;
}
