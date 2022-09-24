//hamster.h
#include "animal.h"

class Hamster : public Animal{
    public:
        Hamster(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Squeak!" << std::endl; }
};