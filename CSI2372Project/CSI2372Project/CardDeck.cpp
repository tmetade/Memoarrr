#include "CardDeck.h"
#include "Deck.h"
#include <algorithm>
using namespace std;

vector<Card> CardDeck::cards;


void CardDeck::Deck<Card>::shuffle()

//static CardDeck& make_CardDeck()
//{
//    return NULL;
//}

//static CardDeck& make_CardDeck() is the only public method for CardDeck. The method has to
//always return the same CardDeck during the execution of the program.

//An object of type CardDeck can not be copied or assigned

