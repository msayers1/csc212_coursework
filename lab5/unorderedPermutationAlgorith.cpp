#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <array>

std::vector<int>* options(std::vector<int> * input, int size, int* counter); 
void print(std::vector<int> * input, int counter);

int main(){
    int * counter = new int(1);
    std::vector<int> *input = new std::vector<int>{1, 2, 3};
    //std::vector<int> *input2 = new std::vector<int>{1, 2, 3, 4, 5};
    //std::vector<int> *input3 = new std::vector<int>{71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> *ouput = options(input, 3, counter);
    *counter = 1;
    //std::vector<int> *ouput2 = options(input2, 5, counter);
    //std::vector<int> *ouput3 = options(input3, 71);
    // std::cout << output << std::endl;
    // std::cout << output2 << std::endl;
    // std::cout << output3 << std::endl;

}

// std::vector<std::vector<int>>* permutation(std::vector<std::vector<int>> * input){
//     std::vector<int> * permutations;
//     size_t size = (*input).size();
//     if(size == 1){
//         return input;
//     }
//     std::vector<std::vector<int>> * n_minus_one = input[];
//     (*n_minus_one).pop_back();
//     int n_minus_one_size = (*n_minus_one).size();
//     int temp, temp2;
//     int counter = 0;
//     std::cout << n_minus_one_size << std::endl;
//     permutations = options(n_minus_one);
//     (*permutations).push_back((*input)[i][size - 1]);
//     print(permutations);
//     for (int i = 1; i <= n_minus_one_size; i++){
//         if(counter % 2 == 1){
//             temp = (*n_minus_one)[n_minus_one_size];
//             temp2 = (*n_minus_one)[0];
//             (*n_minus_one)[size-1] = temp2;
//             (*n_minus_one)[0] = temp;
            
//         }else{
//             temp = (*n_minus_one)[n_minus_one_size];
//             temp2 = (*n_minus_one)[i];
//             (*n_minus_one)[size-1] = temp2;
//             (*n_minus_one)[0] = temp;
//         }
        
//         counter++;
//     }

//     return permutations;
// }

std::vector<int>* options(std::vector<int> * input, int size, int *counter){
    std::vector<int> * permutations;
    //size_t size = (*input).size();
    if(size == 1){
        return input;
    }
    std::vector<int> * n_minus_one = input;
    //(*n_minus_one).pop_back();
    int n_minus_one_size;
    int temp, temp2;
    for (int i = 0; i < size; i++) {
        //std::cout << n_minus_one_size << std::endl;
        n_minus_one_size = size - 1;
        permutations = options(input, n_minus_one_size, counter);
        //(*permutations).push_back((*input)[size - 1]);
        if(i % 2 == 1){
            temp = (*permutations)[n_minus_one_size];
            temp2 = (*permutations)[0];
            (*permutations)[n_minus_one_size] = temp2;
            (*permutations)[0] = temp;
        }else{
            temp = (*permutations)[n_minus_one_size];
            temp2 = (*permutations)[i];
            (*permutations)[n_minus_one_size] = temp2;
            (*permutations)[i] = temp;
        }
        //std::cout << "Here is n : " << n_minus_one_size << ", Here is counter " << i << std::endl; 
        print(permutations, (*counter));
        (*counter)++;
    }
        
    return permutations;
}

void print(std::vector<int> * input, int counter){
    // int size = (*input).size();
    // for(int i=0; i < size; i++){
    //     std::cout << input[i] << std::endl;
    // }
    int size = (*input).size();
    std::cout << counter << ": ";
    for(int i = 0; i < size; i++){
        std::cout << (*input)[i] << " ";
    }
    std::cout << std::endl;
}



// void options(int n){
//     if( n == 1){
//         std::cout << 1 << std::endl;
//         return;
//     }
//     //std::string permutation = "";
//     std::vector<std::vector<int> > * permutations;
//     //int[n] * single_permutation;
//     int array[n];
        
//     for (int i = 1; i <= n; i++){
//         array[0] = i;
//         (*permutations)[0].push_back(i);

//     }

//     //std::vector<int> old_permutation = (*permutations)[0];    
//     //std::vector<int> * new_permutation;

//     for (int i = 1; i <= n - 1; i++){
//             options(n - 1);
//     }
//     //cout << 
//     //std::cout << permutation << std::endl;
// }

// std::vector<int> perumations(std::vector<int> elements){

// }

// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/ for the algortithm. 
// The algorithm generates (n-1)! permutations of the first n-1 elements, adjoining the last element to each of these. This will generate all of the permutations that end with the last element.
// If n is odd, swap the first and last element and if n is even, then swap the ith element (i is the counter starting from 0) and the last element and repeat the above algorithm till i is less than n.
// In each iteration, the algorithm will produce all the permutations that end with the current last element.