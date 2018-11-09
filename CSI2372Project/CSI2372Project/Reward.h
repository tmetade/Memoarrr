#ifndef Reward_h
#define Reward_h

#include <stdio.h>
#include <iostream>
#include "DeckCard.h"

class Reward : public DeckCard
{
public:
    friend class RewardDeck;

    friend std::ostream& operator<<(std::ostream& os, const Reward&);
    int getReward() const { return rewardValue; };
private:  
    Reward(int rubyValue);
    ~Reward();
    
    int rewardValue;
};

#endif
