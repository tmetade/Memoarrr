//
//  DeckCardFactory.h
//  CSI2372Project
//
//  Created by Rohan Kanjani on 2018-11-09.
//  Copyright © 2018 Tyler Metade. All rights reserved.
//

#ifndef DeckCardFactory_h
#define DeckCardFactory_h

#include "DeckCard.h"

class DeckCardFactory {
public:
    virtual DeckCard *createCard() = 0;
    virtual DeckCard *createReward() = 0;
};

#endif /* DeckCardFactory_h */
