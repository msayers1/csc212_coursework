#include <iostream>

int function1(int x, int *y){
    x = 90 + x;
    *y = 43 * x;
    return x;
}

int* function2(int x){
    int y = 23 * x;
    return &y;
}


int main(){
    int x = 3, y = 4;
    x = function1(x, &y);
    std::cout << x << " - " << y << std::endl;
    // int x = 3, y = 4;
    // int *z = function2(y);
    // x = z;
    // std::cout << x << " - " << y << std::endl;

}