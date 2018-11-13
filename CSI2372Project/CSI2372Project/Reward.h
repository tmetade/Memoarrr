#ifndef Reward_h
#define Reward_h

#include <stdio.h>
#include <iostream>

class Reward
{
    friend class RewardDeck;
public:
    friend std::ostream& operator<<(std::ostream& os, const Reward&);
    
private:  
    Reward(int rubyValue);
    ~Reward();
    
    int rewardValue;
};

#endif
