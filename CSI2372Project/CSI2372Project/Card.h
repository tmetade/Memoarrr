#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <iostream>

//The public interface of Card is to include conversion operators to type FaceAnimal and FaceBackground

class Card
{
public:
    enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
    enum FaceBackground {Red, Green, Purple, Blue, Yellow};
    std::string face[3];
    
    static FaceBackground getFaceBackgroundAtIndex(int index);
    static FaceAnimal getFaceAnimalAtIndex(int index);
    
    friend class CardDeck;
    
    std::string operator()(int row) { return face[row]; }
    
    operator const FaceAnimal() const { return cardAnimal; };
    
    operator const FaceBackground() const { return cardColour; };

private:
    Card(FaceAnimal, FaceBackground);
    FaceAnimal cardAnimal;
    FaceBackground cardColour;
};

#endif
