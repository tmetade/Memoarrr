#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <iostream>
#include "Reward.h"


class Player
{
    
public:
    Player(std::string playerName);
    ~Player();
    
    enum Side {top, bottom, left, right};
    
    std::string getName() const { return playerName; };
    void setActive(bool playerActive){ active = playerActive; };
    bool isActive() { return active; };
    int getNRubies() const { return nRubies; };
    void addReward(const Reward& reward);
    void setDisplayMode(bool endOfGame);
    Side getSide(){ return playerSide; };
    void setSide(Side side){ playerSide = side; };
    
    friend std::ostream& operator<<(std::ostream& os, const Player&);
    
private:
    std::string playerName;
    Side playerSide;
    bool active;
    int nRubies;
    std::string outputString;
};

#endif
