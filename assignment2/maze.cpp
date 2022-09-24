//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stack>
#include <typeinfo>
#include "maze.h"

void outputGrid(std::vector<std::vector<std::vector<double>>> * grid_data);
std::vector<std::vector<int>> findNeighbors(std::vector<int> current_cell, std::vector<std::vector<std::vector<double>>> grid_data);
void writeGridToFile(std::vector<std::vector<std::vector<double>>> * grid_data, std::string filename);

Maze::Maze(int rows, int cols, unsigned int seed, std::string filename ){
    std::vector<double> default_cell = {15, 0}; 
    std::vector<std::vector<double>> default_standard(rows, default_cell);
    std::vector<std::vector<std::vector<double>>> grid_data(cols, default_standard);
    int last_index_rows = rows - 1;
    int last_index_cols = cols - 1;
    //set entrace to open to north. 
    grid_data[0][0][0] = 7;
    //set exit to open to south. 
    grid_data[last_index_rows][last_index_cols][0] = 11;
    //creates a stack to track current cell ( A in sudo code provided)
    std::stack<std::vector<int>> current_stack;
    grid_data[0][0][1] = 1;
    //initializes and sets up the current cell
    std::vector<int> current_cell = {0, 0}; 
    // adds the current cell to the stack. 
    current_stack.push(current_cell);
    std::srand(seed);
    while(!current_stack.empty()){
        //removes the top cell on the stack.
        current_stack.pop();
        std::cout << "current cell is " << current_cell[0] << " by " << current_cell[1] << std::endl;
        if(!current_stack.empty()) std::cout << "top of the stack after removing one is cell is " << current_stack.top()[0] << " by " << current_stack.top()[1] << std::endl;            
        std::vector<std::vector<int>> neighbors = findNeighbors(current_cell, grid_data);
        std::cout << "The size of neighbors is " << neighbors.size() <<  " and the if statement is " << !neighbors.empty() << std::endl;
        if(!neighbors.empty()){
            current_stack.push(current_cell);
            

            int random_number = std::rand();
            std::cout << "Random number: " << random_number << std::endl;
            int random_index = random_number / ((RAND_MAX + 1u) / neighbors.size());
            // if(current_cell == std::vector<int>{0, 0}){
            //     random_index = 0;
            // }
            std::cout << "this is the random index " << random_index << " and the size of neigbors is " <<neighbors.size() << std::endl;
            int neigh_row = neighbors[random_index][0];
            int neigh_col = neighbors[random_index][1];
            // std::cout << "this is the NSEW index is " << neighbors[random_index][2] << std::endl;
            switch(neighbors[random_index][2]){
                case 1:
                    grid_data[current_cell[0]][current_cell[1]][0] = grid_data[current_cell[0]][current_cell[1]][0] - 8;
                    grid_data[neigh_row][neigh_col][0] = grid_data[neigh_row][neigh_col][0] - 4;
                    break;
                case 2:
                    grid_data[current_cell[0]][current_cell[1]][0] = grid_data[current_cell[0]][current_cell[1]][0] - 4;
                    grid_data[neigh_row][neigh_col][0] = grid_data[neigh_row][neigh_col][0] - 8;
                    break;
                case 3:
                    grid_data[current_cell[0]][current_cell[1]][0] = grid_data[current_cell[0]][current_cell[1]][0] - 2;
                    grid_data[neigh_row][neigh_col][0] = grid_data[neigh_row][neigh_col][0] - 1;
                    break;
                case 4:
                    grid_data[current_cell[0]][current_cell[1]][0] = grid_data[current_cell[0]][current_cell[1]][0] - 1;
                    grid_data[neigh_row][neigh_col][0] = grid_data[neigh_row][neigh_col][0] - 2;
                    break;
            }
            grid_data[neigh_row][neigh_col][1] = 1;
            current_cell = { neigh_row, neigh_col };
            current_stack.push(current_cell);
            std::cout << "top of the stack is cell is " << current_stack.top()[0] << " by " << current_stack.top()[1] << std::endl;
            std::cout << "current cell is " << neigh_row << " (" << current_cell[0] << ")" << " by " << neigh_col << " (" << current_cell[1] << ")" << std::endl;
        } else {
            if(!current_stack.empty()) current_cell = current_stack.top();
        }
    }
    
    //OutputGridToFile(&grid_data);
    writeGridToFile(&grid_data, filename);



}


void outputGrid(std::vector<std::vector<std::vector<double>>> * grid_data){
    int rows = (*grid_data).size();
    for(int i = 0; i < rows; i++){
        int cols = (*grid_data)[0].size();
        for(int j = 0; j < cols; j++){
            std::cout << "Cell " << i << " by " << j << " has a value of ";
            std::cout << (*grid_data)[i][j][0];
            (*grid_data)[i][j][1] == 1?std::cout << " and has been visited.":std::cout << " and has not been visited";
            std::cout << std::endl;
        }
    }
}

// void outputStack(std::stack<std::vector<int>> * stack){
//     int size = (*stack).size();
//     std::cout << "Current Stack is at " << size << " level" << std::endl;
//     for(int i = 0; i < size; i++){
//         std::cout << i << ": Cell " << stack[i][0] << " by " << stack[i][0] << std::endl;
//     }
// }


void writeGridToFile(std::vector<std::vector<std::vector<double>>> * grid_data, std::string file_name){
    // Open our file with write permissions
    //std::string file_name = "output.txt";
    std::ofstream output_file(file_name);

    // Use an iterator to traverse the outer dimension
    for(std::vector<std::vector<std::vector<double>>>::const_iterator i = (*grid_data).begin(); i != (*grid_data).end(); ++i){
        // Use an interator to traverse the inner dimention
        for(std::vector<std::vector<double>>::const_iterator j = i->begin(); j != i->end(); ++j){
            // Output each element to the file with a space at the end
            output_file << (*j)[0] << " ";
        }
        // Output a newline symbol to the file
        output_file << "\n";
    }
    
}

std::vector<std::vector<int>> findNeighbors(std::vector<int> current_cell, std::vector<std::vector<std::vector<double>>> grid_data){
    std::vector<std::vector<int>> neighbors;
    int row = current_cell[0];
    int col = current_cell[1];
    // std::cout << row << " by " << col << std::endl;
    int check_row = row - 1;
    int check_col = col;
    double visited = 1;
    int row_max = grid_data.size();
    int col_max = grid_data[0].size();
    //std::cout << "grid value is a type of " << typeid(visited).name() << std::endl;
    //std::cout << "grid value is a type of " << typeid(grid_data[check_row][check_col][1]).name() << std::endl;
    
    // check north
    if(0 <= check_row && check_row < row_max && 0 <= check_col && check_col < col_max){
        std::cout << "checking the north: " <<  (grid_data[check_row][check_col][1] != visited) << std::endl;
        if(grid_data[check_row][check_col][1] != visited){
            std::cout << "recording the north neighbor. " << std::endl;
            neighbors.push_back({check_row, check_col, 1});
        }
    }

    //check south
    check_row = check_row + 2;
    if(0 <= check_row && check_row < row_max && 0 <= check_col && check_col < col_max){
        std::cout << "checking the south: " <<  (grid_data[check_row][check_col][1] != visited) << std::endl;
        if(grid_data[check_row][check_col][1] != visited){
            std::cout << "recording the south neighbor. " << std::endl;
            neighbors.push_back({check_row, check_col, 2});
        }
    }
    //check east
    check_row--;
    check_col++;
    if(0 <= check_row && check_row < row_max && 0 <= check_col && check_col < col_max){
        std::cout << "checking the east: " <<  (grid_data[check_row][check_col][1] != visited) << std::endl;
        if(grid_data[check_row][check_col][1] != visited){
            std::cout << "recording the east neighbor. " << std::endl;
            neighbors.push_back({check_row, check_col, 3});
        }
    }

    //check west
    check_col = check_col - 2;
    if(0 <= check_row && check_row < row_max && 0 <= check_col && check_col < col_max){
        std::cout << "checking the west: " <<  (grid_data[check_row][check_col][1] != visited) << std::endl;
        if(grid_data[check_row][check_col][1] != visited){
            std::cout << "recording the west neighbor. " << std::endl;
            neighbors.push_back({check_row, check_col, 4});
        }
    }
        
    return neighbors;
}