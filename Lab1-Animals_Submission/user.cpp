// user.cpp
#include "bird.h"
#include "snake.h"
#include "hamster.h"
#include "dog.h"
#include "cat.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int GetInputFromUser(){
        cout << "Please select an animal ( 1: Dog, 2: Cat, 3: Bird, 4: Snake, 5: Hamster) " << endl;
        int animal_type;
        cin >> animal_type;
        return animal_type;
}
        

int main(int argc, char **argv){
    int number_of_animals = atoi(argv[1]);
    Animal** arr = new Animal*[number_of_animals];
    for (int i = 0; i < number_of_animals; ++i) {
        //Calls function to get user input. 
        int animal_type = GetInputFromUser();
        int animal_hunger = atoi(argv[i + 2]);
        switch(animal_type){
            case 1:
                arr[i] = new Dog(animal_hunger);
                break;
            case 2:
                arr[i] = new Cat(animal_hunger);
                break;
            case 3:
                arr[i] = new Bird(animal_hunger);
                break;
            case 4:
                arr[i] = new Snake(animal_hunger);
                break;
            case 5:
                arr[i] = new Hamster(animal_hunger);
                break;
            default:
                arr[i] = new Hamster(animal_hunger);
                break;
        }
    }

    for (int i = 0; i < number_of_animals; i++) {
        Animal* specific_animal = arr[i];
        specific_animal->Speak();
        cout << specific_animal->GetHunger() << endl;
    }
}