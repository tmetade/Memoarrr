#ifndef Deck_h
#define Deck_h

#include <stdio.h>
#include "DeckCard.h"
#include "Card.h"
#include <vector>

class Deck {
public:
    Deck();
    ~Deck();
    
    std::vector<DeckCard> cards;
    
    DeckCard* getNext();

    virtual void shuffle() = 0;
    virtual bool isEmpty() = 0;
    
    virtual DeckCard *createCard(Card::FaceAnimal animal, Card::FaceBackground background) = 0;
    virtual DeckCard *createReward(int rubies) = 0;
};

#endif
