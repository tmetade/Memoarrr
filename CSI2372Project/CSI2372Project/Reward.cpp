#include "Reward.h"

Reward::Reward(int rubyValue)
{
    rewardValue = rubyValue;
}
Reward::~Reward()
{
    
}

std::ostream& operator<<(std::ostream& os, const Reward &r)
{
    os << "reward: "<< r.rewardValue << std::endl;
    return os;
}
