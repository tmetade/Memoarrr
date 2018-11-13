#include "Deck.h"

//Design a class Deck<C> as an abstract factory class that will be used to create a set of cards or a set of rewards. The type parameter <C> is intended to be one of {Card|Reward}.

template <class C>
void Deck<C>::shuffle()
{
    //shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library
}

template <class C>
bool Deck<C>::isEmpty() const
{
    //shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library
}

template <class C>
C* Deck<C>::getNext()
{
    // returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available
}



