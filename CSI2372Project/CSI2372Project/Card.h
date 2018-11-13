#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <iostream>

class Card
{
    friend class CardDeck;
public:
    enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
    enum FaceBackground {Red, Green, Purple, Blue, Yellow};
    std::string face[3];
    friend class CardDeck;
private:
    Card operator()(int row);
    Card(FaceAnimal, FaceBackground);
    ~Card();
};

#endif
