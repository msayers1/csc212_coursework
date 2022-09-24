//snake.h
#include "animal.h"

class Snake : public Animal{
    public:
        Snake(float initial_hunger) : Animal(initial_hunger){};
        void Speak() { std::cout << "Hissss!" << std::endl; }
};