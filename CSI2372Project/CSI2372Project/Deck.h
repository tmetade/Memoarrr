#ifndef Deck_h
#define Deck_h

#include <stdio.h>

class Deck
{
    Deck();
    ~Deck();
    
    virtual void shuffle() = 0;
    //C* getNext()
    virtual bool isEmpty() const = 0;
};

#endif
