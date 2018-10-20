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
    
    std::string getName() const { return name; };
    void setActive(bool playerActive){ active = playerActive; };
    bool isActive() { return active; };
    int getNRubies() const { return nRubies; };
    void addReward(const Reward& reward);
    void setDisplayMode(bool endOfGame);
    
    friend std::ostream& operator<<(std::ostream& os, const Player&);
    
private:
    std::string name;
    bool active;
    int nRubies;
};

#endif
