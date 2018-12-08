//#define TEST_CARD_DECK_

#include "CardDeck.h"
#include "Deck.h"
#include <algorithm>
#include <vector>

using namespace std;

vector<Card> CardDeck::cards;

void CardDeck::shuffle()
{
    random_shuffle(cards.begin(), cards.end());
}

Card* CardDeck::getNext()
{
    if (!isEmpty())
        return &(cards[numCards-- - 1]);
    else
        return nullptr;
}

CardDeck& CardDeck::make_CardDeck()
{
    CardDeck* newDeck = new CardDeck();
    
    for (int x = 0; x < NUM_OF_ANIMALS; x++)
    {
        for (int y = 0; y < NUM_OF_BACKGROUNDS; y++)
        {
            cards.push_back(Card(Card::getFaceAnimalAtIndex(x), Card::getFaceBackgroundAtIndex(y)));
        }
    }    
    return *newDeck;
}

#ifdef TEST_CARD_DECK_
int main()
{
    CardDeck *cardDeck = &CardDeck::make_CardDeck();
    Card *card = cardDeck->getNext();
    bool isCard = card !=nullptr;
    
    CardDeck *cardDeck2 = &CardDeck::make_CardDeck();
    cardDeck2->shuffle();
    Card *card2 = cardDeck2->getNext();
    bool isShuffled = card != card2;
    
    if(isCard && isShuffled)
        std::cout << "CardDeck has passed its tests" << std::endl;
    else
        std::cerr << "CardDeck didnt pass its tests" << std::endl;
}
#endif
