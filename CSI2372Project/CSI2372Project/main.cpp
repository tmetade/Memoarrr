#include <iostream>

#include "Board.h"
#include "CardDeck.h"
#include "Deck.h"
#include "Player.h"
#include "RewardDeck.h"
#include "Rules.h"

using namespace std;

int main(int argc, const char * argv[]) {
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
        //for each player reveal 3 cards
        
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
