//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>

int mystery(int *arr, int n);

int main(int argc, char* argv[]){
      int *arr = new int[20]{1,2,5,3,4,200,495,29,3,4,5,3};
      int output = mystery(arr, 5);
      std::cout << output << std::endl;
      output = mystery(arr, 6);
      std::cout << output << std::endl;  
      output = mystery(arr, 15);
      std::cout << output << std::endl;  
}

int mystery(int *arr, int n){
    if( n == 1) return arr[0];
    int val = mystery(arr + 1, n- 1); 
    return (arr[0] > val)? arr[0]: val;
}

//1. B
