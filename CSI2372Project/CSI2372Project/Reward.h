#ifndef Reward_h
#define Reward_h

#include <stdio.h>
#include <iostream>

class Reward
{
    friend class RewardDeck;
public:
    friend std::ostream& operator<<(std::ostream& os, const Reward&);
    operator const int() const { return rewardValue; };

private:
    int rewardValue;
    Reward(int rubyValue);
};

#endif
