#include <iostream>
#include <stdlib.h>

int sum(int n); 

int main(){
    int output = sum(10);
    int output2 = sum(100);
    std::cout << output << std::endl;
    std::cout << output2 << std::endl;
}

int sum(int n){
    if ( n == 0) {
        return 0;
    } 
    unsigned long sub_sum = sum(n - 1);

    unsigned long total = n + sub_sum;
    
    return total;
}