//#define TEST_REWARD_

#include "Reward.h"

Reward::Reward(int rubyValue)
{
    rewardValue = rubyValue;
}

std::ostream& operator<<(std::ostream& os, const Reward &r)
{
    os << "reward: "<< r.rewardValue << std::endl;
    return os;
}

#ifdef TEST_REWARD_
#include "RewardDeck.h"
int main() {
    RewardDeck *rewardDeck = &RewardDeck::make_RewardDeck();
    Reward *reward = rewardDeck->getNext();
    bool isReward = *reward == 4;
    
    if(isReward)
        std::cout << "Reward has passed its tests" << std::endl;
    else
        std::cerr << "Reward didnt pass its tests" << std::endl;
}
#endif
