//main.cpp:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>

void ReadFile(std::string file_name, std::vector<std::vector<std::vector<double>>> * grid_data);
void outputGrid(std::vector<std::vector<std::vector<double>>> * grid_data);

int main(int argc, char* argv[]){
    std::string filename = argv[1];
    int rows = std::stoi(argv[2]);
    int columns = std::stoi(argv[3]);
    int startRow = std::stoi(argv[4]);
    int startCol = std::stoi(argv[5]);
    int conn = std::stoi(argv[6]);
    std::vector<std::vector<std::vector<double>>> grid_data;
    ReadFile(filename, &grid_data);
    outputGrid(&grid_data);
    return 0;
}


void outputGrid(std::vector<std::vector<std::vector<double>>> * grid_data){
    int rows = (*grid_data).size();
    for(int i = 0; i < rows; i++){
        int cols = (*grid_data)[0].size();
        for(int j = 0; j < cols; j++){
            std::cout << (*grid_data)[i][j][0];
        }
        std::cout << std::endl;
    }
}

void ReadFile(std::string file_name, std::vector<std::vector<std::vector<double>>> * grid_data){
    // Opens the file for reading
    std::ifstream file(file_name);
    std::vector<double> cell;
    // Creates a string to hold each line in temporarily
    std::string str;
   
    //int counter = 0;
    // Iterates over the file, storing one line at a time into `str`
    while (getline(file, str)) {
        // Create a temporary 1D Vector of doubles
       std::vector<std::vector<double>> new_row;

       // Create a stringstream object with our line of integers from the file
       std::istringstream ss(str);

       // Create a double that will hold our extracted value from the string
       double token;

        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            // std::string stringtoken = std::to_string(token);
            // std::cout << stringtoken << std::endl;
            cell.push_back(token);
            cell.push_back(0);
            std::cout << std::to_string(token) << '-0-' << std::to_string(cell[0]) << std::to_string(cell[1]) << std::endl;
            new_row.push_back(cell);
        }

        // The line is empty, push our completed row into our 2D vector
        if(new_row.size() != 0){
            grid_data->push_back(new_row);
        } 
        
    }
}

