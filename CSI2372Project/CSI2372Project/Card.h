#ifndef Card_h
#define Card_h

#include <stdio.h>
#include <iostream>
#include "DeckCard.h"

class Card : public DeckCard
{
public:
    friend class CardDeck;

    enum FaceAnimal {Crab, Penguin, Octopus, Turtle, Walrus};
    enum FaceBackground {Red, Green, Purple, Blue, Yellow};
    const static int rows = 3;
    
    //might have to be a pointer
    std::string face[rows];
    
    static FaceBackground getFaceBackgroundAtIndex(int index);
    static FaceAnimal getFaceAnimalAtIndex(int index);
    
    //void print();
    
private:
    Card(FaceAnimal, FaceBackground);
    std::string operator()(int row){
        return face[row];
    }
    int getNRows(){ return rows; }
    ~Card();
};

#endif
