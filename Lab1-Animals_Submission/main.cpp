// main.cpp
#include "bird.h"
#include "snake.h"
#include "hamster.h"
#include "dog.h"
#include "cat.h"

int main(){
    Cat cat1(50);	// object constructed during compile-time
    Dog* dog1 = new Dog(40);	// object constructed during run-time. 'dog1' is a pointer.
    Bird bird1(35);
    Hamster bobby(45);
    Snake* gerald = new Snake(31);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;
    std::cout << "Bird hunger: " << bird1.GetHunger() << std::endl;
    std::cout << "Bobby's hunger: " << bobby.GetHunger() << std::endl;
    std::cout << "Gerald's hunger: " << gerald->GetHunger() << std::endl;

    cat1.Eat(10);
    dog1->Eat(40);
    bird1.Eat(4);
    bobby.Eat(42);
    gerald->Eat(33);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;
    std::cout << "Bird hunger: " << bird1.GetHunger() << std::endl;
    std::cout << "Bobby's hunger: " << bobby.GetHunger() << std::endl;
    std::cout << "Geralds's hunger: " << gerald->GetHunger() << std::endl;
    
    cat1.Speak();
    dog1->Speak();
    bird1.Speak();
    bobby.Speak();
    gerald->Speak();

    cat1.Exercise(20);
    dog1->Exercise(4);
    bird1.Exercise(14);
    bobby.Exercise(12);
    gerald->Exercise(23);

    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;
    std::cout << "Bird hunger: " << bird1.GetHunger() << std::endl;
    std::cout << "Bobby's hunger: " << bobby.GetHunger() << std::endl;
    std::cout << "Geralds's hunger: " << gerald->GetHunger() << std::endl;
}