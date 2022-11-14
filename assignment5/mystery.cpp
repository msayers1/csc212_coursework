//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>

int mystery(int *arr, int n);
bool mystery2(int n, int i);
int sort (int* arr , int n);
int mystery3(std::stack<int> stack);

int main(int argc, char* argv[]){
      int *arr = new int[20]{1,2,5,3,4,200,495,29,3,4,5,3};
      int output = mystery(arr, 5);
      std::cout << output << std::endl;
      output = mystery(arr, 6);
      std::cout << output << std::endl;  
      output = mystery(arr, 15);
      std::cout << output << std::endl;  
      int n = 45;
      int i = 5;
      bool output2 = mystery2(n, i);
      std::cout << output2 << std::endl;  
      n = 21;
      i = 4;
      output2 = mystery2(n, i);
      std::cout << output2 << std::endl;  
      n = 33;
      i = 4;
      output2 = mystery2(n, i);
      std::cout << output2 << std::endl;
      n = 36;
      i = 4;
      output2 = mystery2(n, i);
      std::cout << output2 << std::endl;
      int *arr2 = new int[20]{12,6,4,44,200,495,29,3,34,45,3};
      output = sort(arr2, 4);
      std::cout << output << std::endl;  
      for(int i = 0; i < 5; i++){
        std::cout << arr2[i] << ", ";  
      }
      std::cout << std::endl;
      output = sort(arr2, 8);
      std::cout << output << std::endl;  
      for(int i = 0; i < 8; i++){
        std::cout << arr2[i] << ", ";  
      }
      std::cout << std::endl;
      std::stack<int> stack2;
      stack2.push(7);
      stack2.push(20);
      stack2.push(300);
      stack2.push(5);
      stack2.push(10);
      output = mystery3(stack2);
      std::cout << output << std::endl;        
}

int mystery(int *arr, int n){
    if( n == 1) return arr[0];
    int val = mystery(arr + 1, n- 1); 
    return (arr[0] > val)? arr[0]: val;
}
//1. B


bool mystery2(int n, int i ) { 
    if (n <= 2) 
        return (n == 2) ? true : false ;
    if (n % i == 0)
        return false ;
    if ( i * i > n)
        return true ;
    return mystery2(n,	i + 1);
}
//2. C

int sort (int* arr , int n) {
    if(n <= 1) return 0;
    
    sort(arr , n-1);
    
    int tmp = arr[n-1];
    int j = n-2;
    while ( j >= 0 && arr[j] > tmp ) {
            arr[j+1] = arr[j];
            j--;
    }
    arr [j+1] = tmp ;
   for(int i = 0; i < n; i++){
        std::cout << arr[i] << ", ";  
    }
    std::cout << std::endl;
}


int mystery3(std::stack<int> stack){
    int result = 0;
    int loop = stack.size();
    for ( int i = 0 ; i < loop ; i++) {
        std::cout << "? !(i%2)" << (!(i%2)?"true":"false") << "for " << i << std::endl; 
        if(!(i%2)){
            result+=stack.top();
        } else {
            result*=stack.top();
        }
        stack.pop();
    }
    return result;
}