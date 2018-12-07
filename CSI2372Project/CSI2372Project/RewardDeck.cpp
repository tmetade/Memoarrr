//#define TEST_REWARD_DECK_

#include "RewardDeck.h"
#include <vector>

using namespace std;

vector<Reward> RewardDeck::rewards;

RewardDeck& RewardDeck::make_RewardDeck()
{
    RewardDeck* newRewardDeck = new RewardDeck();
    rewards.push_back(Reward(1));
    rewards.push_back(Reward(1));
    rewards.push_back(Reward(1));
    rewards.push_back(Reward(2));
    rewards.push_back(Reward(2));
    rewards.push_back(Reward(3));
    rewards.push_back(Reward(4));
    
    return *newRewardDeck;
}

Reward* RewardDeck::getNext() {
    if (!isEmpty())
        return &(rewards[numCards-- - 1]);
    else
        return nullptr;
}

void RewardDeck::shuffle() {
    random_shuffle(rewards.begin(), rewards.end());
}

#ifdef TEST_REWARD_DECK_
int main()
{
    RewardDeck *rewardDeck = &RewardDeck::make_RewardDeck();
    Reward *reward = rewardDeck->getNext();
    bool isReward = reward != nullptr;
    
    RewardDeck *rewardDeck2 = &RewardDeck::make_RewardDeck();
    rewardDeck2->shuffle();
    Reward *reward2 = rewardDeck2->getNext();
    bool isShuffled = reward != reward2;
    
    if(isReward && isShuffled)
        std::cout << "RewardDeck has passed its tests" << std::endl;
    else
        std::cerr << "RewardDeck didnt pass its tests" << std::endl;
}
#endif
