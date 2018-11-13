#ifndef Deck_h
#define Deck_h

#include <stdio.h>

template <class C>
class Deck
{
public:
    bool isEmpty() const;
    C* getNext();
    
protected:
        void shuffle();
};

#endif
