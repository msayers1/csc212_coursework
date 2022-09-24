//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include "DynamicArray.h"

void outputArray(DynamicArray thisDynamicArray);

int main(){
    //DynamicArray dynamicArray;
    //outputArray(dynamicArray);
    DynamicArray dynamicArray3(4, 10, 0);
    outputArray(dynamicArray3);
    DynamicArray dynamicArray2(4, 10);
    outputArray(dynamicArray2);
    for(int i = 0; i < 12; ++i){
        //std::cout << "Value about to append " << i << std::endl;
        dynamicArray2.append(i);
    }
    for(int i = 0; i < 12; ++i){
        //std::cout << "Value about to prepend " << i << std::endl;
        dynamicArray2.prepend(i);
    }
    outputArray(dynamicArray2);
    unsigned int index;
    dynamicArray2.findFirstOf(7, &index);
    std::cout << "7 was found at " << index << std::endl;
    dynamicArray2.findLastOf(7, &index);
    std::cout << "7 was last found at " << index << std::endl;
    dynamicArray2.removeFirst();
    outputArray(dynamicArray2);
    dynamicArray2.removeLast();
    outputArray(dynamicArray2);
    dynamicArray2.clear();
    outputArray(dynamicArray2);
        
}


void outputArray(DynamicArray thisDynamicArray){
    std::cout << "The array has a length of " << thisDynamicArray.getLength();
    std::cout << ", and a capacity of " << thisDynamicArray.getCapacity();
    std::cout << ", and a scaling factor of " << thisDynamicArray.getScalingFactor();
    std::cout << ", and the array is " << thisDynamicArray.toString() << std::endl;
}