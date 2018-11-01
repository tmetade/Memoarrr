#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <iostream>

class Card
{
public:
    enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
    enum FaceBackground {Red, Green, Purple, Blue, Yellow};
    std::string face[3];
private:
    Card operator()(int row);
    Card(FaceAnimal, FaceBackground);
    ~Card();
};

#endif
