//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include "maze.h"
#include <ctime>

int main(int argc, char* argv[]){
//<seed>  the seed value for the random number generator
// <N>     number of rows in the grid N > 0
// <M>     number of cols in the grid M > 0
// <fname> file name for the output
unsigned int seed = std::stoi(argv[1]);
// std::srand(seed);
// int random =  std::rand();
// std::cout << random << std::endl;
int rows = std::stoi(argv[2]);
// std::cout << rows << std::endl;
int cols = std::stoi(argv[3]);
// std::cout << cols << std::endl;
std::string filename = (argv[4]);
// std::cout << filename << std::endl;

uint64_t val;
unsigned long c_start, c_end;
c_start = std::clock();
Maze new_maze(rows, cols, seed, filename );
c_end = std::clock();
float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
std::cout << "Time:" << output << std::endl;

}