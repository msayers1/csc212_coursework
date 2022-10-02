//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>

void takeInput(int * input);

int main(int argc, char* argv[]){

    int input;
    bool running = true;
 
    while(running == true){
        std::cout << "Press 1 for Blah" << std::endl;
        std::cout << "Press 2 for Blah Blah" << std::endl;
        std::cout << "Press 3 for Blah Blah Blah" << std::endl;
        std::cout << "Press 0 to quit" << std::endl;
        std::cout << "Please Make a selection:";
        std::cin >> input;
        takeInput(&input);
    }
}

void takeInput(int * input){
    switch(*input){
        case 1:
            std::cout << "Press 1 for Blah" << std::endl;
            break;
        case 2:
            std::cout << "Press 1 for Blah Blah" << std::endl;
            break;
        case 3:
            std::cout << "Press 1 for Blah Blah Blah" << std::endl;
            break;
        case 4:
            std::cout << "Press 1 for Blah Blah Blah" << std::endl;
            break;
        default:
            std::cout << "Your input is invalid, Please press 1, 2, 3, or 4." << std::endl;
            break;

    }
}