#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

void options(int n); 

int main(){
    // std::string output = options(2);
    // std::string output2 = options(3);
    // std::string output2 = options(71);
    options(2);
    options(3);
    options(71);
    // std::cout << output << std::endl;
    // std::cout << output2 << std::endl;
}

void options(int n){
    if( n == 1){
        std::cout << 1 << std::endl;
        return;
    }
    int array[n];
        
    for (int i = 1; i <= n){
        array[0] = i;
    }
    //std::string permutation = "";
    std::vector<std::vector<int>> permutations;
    for (int i = 1; i <= n - 1; i++){
            
            //permutation += std::to_string(i) + " ";

    }
    //std::cout << permutation << std::endl;
}

// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/ for the algortithm. 
// The algorithm generates (n-1)! permutations of the first n-1 elements, adjoining the last element to each of these. This will generate all of the permutations that end with the last element.
// If n is odd, swap the first and last element and if n is even, then swap the ith element (i is the counter starting from 0) and the last element and repeat the above algorithm till i is less than n.
// In each iteration, the algorithm will produce all the permutations that end with the current last element.