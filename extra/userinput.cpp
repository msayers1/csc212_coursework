#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
    cout << "Please select an animal ( 1: Dog, 2: Cat, 3: Bird, 4: Snake, 5: Hamster) " << std::endl;
    int animal_type;
    cin >> animal_type;
        switch(animal_type){
            case 1:
                cout << "Dog\n" << argv[2];
                break;
            case 2:
                cout << "Cat\n" << argv[2];
                break;
            case 3:
                cout << "Bird\n" << argv[2];
                break;
            case 4:
                cout << "Snake\n" << argv[2];
                break;
            case 5:
                cout << "Hamster\n" << argv[2];
                break;
            default:
                cout << "Hamster and No real Input.\n" << argv[2];
                break;
        }
}
        