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
    
    return *newDeck;
}

//static CardDeck& make_CardDeck()
//{
//    return NULL;
//}

//static CardDeck& make_CardDeck() is the only public method for CardDeck. The method has to
//always return the same CardDeck during the execution of the program.

//An object of type CardDeck can not be copied or assigned

