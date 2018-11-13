#ifndef RewardDeck_h
#define RewardDeck_h

#include <stdio.h>

#include "Deck.h"
#include "Reward.h"

class RewardDeck : public Deck<Reward>
{
public:
    static RewardDeck& make_RewardDeck();
    
private:
    RewardDeck();
    ~RewardDeck();
    
};

#endif
