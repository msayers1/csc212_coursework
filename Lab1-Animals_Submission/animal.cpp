// Animal.cpp
#include "animal.h"

Animal::Animal(float initial_hunger){
    this->hunger = initial_hunger;
}

float Animal::GetHunger(){
    return this->hunger;
}

void Animal::Eat(float sustenance){
    // Changed sustenance as a negative to reduce hunger. 
    this->hunger -= sustenance;
}

// Added Exercise to increase hunger. 
void Animal::Exercise(float energy){
    this->hunger += energy;
}