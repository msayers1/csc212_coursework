//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>

bool mystery(int n, int i);

int main(int argc, char* argv[]){
      int test = 34;
      int test2 = 2;
      int test3 = 45;
      bool output = mystery(test, 5);
      std::cout << output << std::endl;
      output = mystery(test2, 6);
      std::cout << output << std::endl;  
      output = mystery(test3, 15);
      std::cout << output << std::endl;  
}

bool mystery(int n, int i){
    if( n <= 2)
        return (n==2) ? true : false;
    if( n % i == 0)
        return false;
    if ( i * i > n){
        true;
    return mystery(n, i + 1);
    }
}

//1. B
