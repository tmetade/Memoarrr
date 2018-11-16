#ifndef Reward_h
#define Reward_h

#include <stdio.h>
#include <iostream>

//The public interface of Reward is to include conversion operators to type in returning number of rubies

class Reward
{
    friend class RewardDeck;
public:
    friend std::ostream& operator<<(std::ostream& os, const Reward&);
    
    ~Reward();
private:
    int rewardValue;
    Reward(int rubyValue);
};

#endif
