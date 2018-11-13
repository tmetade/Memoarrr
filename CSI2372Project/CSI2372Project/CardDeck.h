#ifndef CardDeck_h
#define CardDeck_h

#include <stdio.h>
#include "Deck.h"
#include "Card.h"

class CardDeck : public Deck<Card>
{
public:
    static CardDeck& make_CardDeck();
    
private:
    CardDeck();
    ~CardDeck();
};

#endif
