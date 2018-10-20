#include <iostream>

#include "Player.h"

int main(int argc, const char * argv[]) {
    int gameVersion = 0, nPlayers = 0;
    
    while(gameVersion<1 || gameVersion > 3)
    {
        std::cout << "Select your game version: " <<std::endl;
        std::cout << "1-Base Game 2-Expert Display Mode 3-Expert Rules Mode ";
        std::cin >> gameVersion;
    }
    
    while(nPlayers<2 || nPlayers>4)
    {
        std::cout << "Enter the number of players (2-4): ";
        std::cin >> nPlayers;
    }
    
    std::string playerNames[nPlayers];
    std::string tempPlayerName;
    std::cout << "Enter the name of the players: ";
    for(int i=0; i<nPlayers; i++)
    {
        std::cin >> tempPlayerName;
        playerNames[i] = tempPlayerName;
    }
    
    return 0;
}
