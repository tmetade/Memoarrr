#ifndef CardDeck_h
#define CardDeck_h

#include <stdio.h>
#include "Deck.h"
#include "Card.h"

class CardDeck : public Deck<Card>
{
public:
    static CardDeck& make_CardDeck();
    Card* getNext();
    
    CardDeck(const CardDeck&) = delete;
    void operator=(const CardDeck& x) = delete;
    
protected:
    void shuffle();
    
private:
    static const int NUM_OF_BACKGROUNDS = 5;
    static const int NUM_OF_ANIMALS = 5;
    
    CardDeck() : Deck(NUM_OF_ANIMALS*NUM_OF_BACKGROUNDS){}
    static std::vector<Card> cards;
};

#endif
