//main.cpp:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
//#include <gradebook.h>

bool takeInput(int * input);

int main(int argc, char* argv[]){
    //Gradebook gradebook();

    int input;
    bool running = true;
 
    while(running == true){
        std::cout << "Press 1 to print coursework." << std::endl;
        std::cout << "Press 2 to print a category grade." << std::endl;
        std::cout << "Press 3 to print he final frade" << std::endl;
        std::cout << "Press 4 to print minimum grade needed in a category based on a desired grade." << std::endl;
        std::cout << "Press 5 to print a final grade based on inputed category grades." << std::endl;
        std::cout << "Press 6 to add an entry." << std::endl;
        std::cout << "Press 7 to modify an entry." << std::endl;
        std::cout << "Press 0 to quit" << std::endl;
        std::cout << "Please Make a selection:";
        std::cin >> input;
        running = takeInput(&input);
    }
}

bool takeInput(int * input){
    switch(*input){
        case 1:
            //Call function
            std::cout << "print coursework" << std::endl;
            break;
        case 2:
            //Call function
            std::cout << "print a category grade" << std::endl;
            break;
        case 3:
            //Call function
            std::cout << "print he final frade" << std::endl;
            break;
        case 4:
            //Call function
            std::cout << "print minimum grade needed in a category based on a desired grade" << std::endl;
            break;
        case 5:
            //Call function
            std::cout << "print a final grade based on inputed category grades" << std::endl;
            break;
        case 6:
            //Call function
            std::cout << "add an entry" << std::endl;
            break;
        case 7:
            //Call function
            std::cout << "modify an entry" << std::endl;
            break;
        case 0:
            return false;
            break;
        default:
            std::cout << "Your input is invalid, Please press 1, 2, 3, 4, 5, 6, 7, or 0." << std::endl;
            break;

    }
    return true;
}

