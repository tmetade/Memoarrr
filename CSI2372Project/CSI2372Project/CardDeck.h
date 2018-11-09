#ifndef CardDeck_h
#define CardDeck_h

#include <stdio.h>
#include "Deck.h"

class CardDeck : public Deck {
public:
    DeckCard * createCard(Card::FaceAnimal animal, Card::FaceBackground background){
        return new Card(animal, background);
    }
    
    static CardDeck &make_CardDeck(){
        
    }
private:
    
};


#endif
