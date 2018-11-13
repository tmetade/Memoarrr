#include "Card.h"

Card::Card(FaceAnimal animal, FaceBackground colour){
    char colourChar, animalChar;
    
    if(animal == Crab){
        animalChar = 'C';
    } else if (animal == Penguin){
        animalChar = 'P';
    } else if (animal == Octopus){
        animalChar = 'O';
    } else if (animal == Turtle){
        animalChar = 'T';
    } else if(animal == Walrus){
        animalChar = 'W';
    }
    
    if(colour == Red){
        colourChar = 'r';
    } else if(colour == Green){
        colourChar = 'g';
    } else if(colour == Purple){
        colourChar = 'p';
    } else if(colour == Blue){
        colourChar = 'b';
    } else if(colour == Yellow){
        colourChar = 'y';
    }
    
    std::string currentRow;
    for(int i = 0; i < 3; i++){
        currentRow = "";
        for(int j = 0; j < 3; j++){
            if(i == j){
                currentRow += animalChar;
            } else {
                currentRow += colourChar;

            }
        }
        face[i] = currentRow;
    }
    
}

Card::FaceAnimal Card::getFaceAnimalAtIndex(int index){
    return static_cast<FaceAnimal>(index);
}
Card::FaceBackground Card::getFaceBackgroundAtIndex(int index){
    return static_cast<FaceBackground>(index);
}

Card::~Card()
{
    
}
