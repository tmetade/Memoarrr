#ifndef RewardDeck_h
#define RewardDeck_h

#include <stdio.h>
#include <vector>

#include "Deck.h"
#include "Reward.h"

class RewardDeck : public Deck<Reward>
{
    static std::vector<Reward> rewards;
    
public:
    static RewardDeck& make_RewardDeck();
    Reward* getNext();
    
    RewardDeck(const RewardDeck&) = delete;
    void operator=(const RewardDeck& x) = delete;
    
    void shuffle();
    
private:
    RewardDeck() : Deck(7){}
    
};

#endif
