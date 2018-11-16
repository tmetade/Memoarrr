#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <iostream>
#include "Reward.h"


class Player
{
private:
    std::string playerName;
    enum Position {top, bottom, left, right};
    Position playerPos;
    bool active;
    int nRubies;
    std::string outputString;
    
public:
    Player(std::string playerName);
    ~Player();
    
    std::string getName() const { return playerName; };
    void setActive(bool playerActive){ active = playerActive; };
    bool isActive() { return active; };
    int getNRubies() const { return nRubies; };
    void addReward(const Reward& reward);
    void setDisplayMode(bool endOfGame);
    
    friend std::ostream& operator<<(std::ostream& os, const Player&);
};

#endif
