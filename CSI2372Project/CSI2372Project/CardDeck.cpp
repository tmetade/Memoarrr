#include "CardDeck.h"
#include "Deck.h"
#include <algorithm>
#include <vector>

using namespace std;

vector<Card> CardDeck::cards;

void CardDeck::shuffle(){
    random_shuffle(cards.begin(), cards.end());
}

Card* CardDeck::getNext() {
    if (!isEmpty())
        return &(cards[numCards-- - 1]);
    else
        return nullptr;
}

CardDeck& CardDeck::make_CardDeck(){
    CardDeck* newDeck = new CardDeck();
    
    for (int x = 0; x < NUM_OF_ANIMALS; x++) {
        for (int y = 0; y < NUM_OF_BACKGROUNDS; y++) {
            cards.push_back(Card(Card::getFaceAnimalAtIndex(x), Card::getFaceBackgroundAtIndex(y)));
        }
    }
    
    //shuffle cards
    
    return *newDeck;
}
