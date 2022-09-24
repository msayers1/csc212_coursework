//bird.h
#include "animal.h"

class Bird : public Animal{
    public:
        Bird(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Chirp!" << std::endl; }
};