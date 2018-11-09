#ifndef RewardDeck_h
#define RewardDeck_h

#include <stdio.h>
#include "Deck.h"
#include "Reward.h"

class RewardDeck : public Deck {
public:    
    DeckCard * createReward(int nRubies){
        return new Reward(nRubies);
    }
};

#endif
