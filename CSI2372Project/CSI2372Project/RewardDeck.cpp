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
    
    //suffle cards in main
    
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

#if TEST_REWARD_TEST_

std::cout<<"test"<<std::endl;

#else

#endif
