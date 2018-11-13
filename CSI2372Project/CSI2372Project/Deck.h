#ifndef Deck_h
#define Deck_h

#include <stdio.h>

template <class C>
class Deck
{
public:
    virtual bool const isEmpty() { return numCards == 0; }
    virtual C* getNext() = 0;
    virtual void shuffle() = 0;

protected:
    int numCards;
    Deck(int numCards) : numCards{ numCards } {}
};

#endif
