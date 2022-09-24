// main.cpp
#include "./Cat.h"
#include "./Dog.h"

int main(){
    Cat cat1(50);	// object constructed during compile-time
    Dog* dog1 = new Dog(40);	// object constructed during run-time. 'dog1' is a pointer.

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    cat1.Eat(10);
    dog1->Eat(40);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    cat1.Speak();
    dog1->Speak();
}