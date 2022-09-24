// Animal.h
#pragma once
#include <iostream>

class Animal{
    private:
    	float hunger;

    public:
      Animal(float initial_hunger);
    	void Eat(float energy);
    	void Exercise(float e);
    	float GetHunger();
    	virtual void Speak() = 0;
};