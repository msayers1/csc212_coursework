//main.cpp:
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif
// When used, MIN(a,b) will be replaced with ((a < b) ? a : b)
#ifndef MIN
#define MIN(a,b) ((a < b) ? a : b)
#endif

void ReadFile(std::string file_name, std::vector<std::vector<std::vector<double>>> * grid_data);
void outputGrid(std::vector<std::vector<std::vector<double>>> * grid_data);
void findAllConnectedCells(int rows, int columns, int startRow, int startCol, int conn, std::vector<std::vector<std::vector<double>>> * grid_data);

int main(int argc, char* argv[]){
    std::string filename = argv[1];
    int rows = std::stoi(argv[2]);
    int columns = std::stoi(argv[3]);
    int conn = std::stoi(argv[4]);
    std::vector<std::vector<std::vector<double>>> grid_data;
    ReadFile(filename, &grid_data);
    int counter = 0;
    for(int y = 0; y < (rows-1); y++){
        for(int x = 0; x < (columns-1); x++){
            if(grid_data[y][x][0] == 1 && grid_data[y][x][1] == 0){
                counter++;
                grid_data[y][x][1] = 1;
                findAllConnectedCells(rows,columns,y,x,conn, &grid_data);
            }
        }
    
    }
        
    
    std::cout << counter << std::endl; 
    //outputGrid(&grid_data);
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
            cell.push_back(token);
            cell.push_back(0);
            new_row.push_back(cell);
            cell.clear();
        }
        // The line is empty, push our completed row into our 2D vector
        if(new_row.size() != 0){
            grid_data->push_back(new_row);
        }     
    }
}

void checkCell(int yPos, int xPos, int rows, int columns, int startRow, int startCol, int conn, std::vector<std::vector<std::vector<double>>> * grid_data){
    //std::cout << "counter " << (*counter) << ",yPos" << yPos << ",xPos " << xPos << ",value " << (*grid_data)[yPos][xPos][0] << ",visited? " << (*grid_data)[yPos][xPos][1] << ",if statement: " << ((*grid_data)[yPos][xPos][0] == 1 && (*grid_data)[yPos][xPos][1] == 0) << std::endl;
    if((*grid_data)[yPos][xPos][0] == 1 && (*grid_data)[yPos][xPos][1] == 0){
        (*grid_data)[yPos][xPos][1] = 1;
        findAllConnectedCells(rows, columns, yPos, xPos, conn, grid_data);
    }
}
    
    

void findAllConnectedCells( int rows, int columns, int startRow, int startCol, int conn, std::vector<std::vector<std::vector<double>>> * grid_data){
    

    //Set the x and y to north cell
    int xPos = startCol;
    int yPos = MAX(0, (startRow-1));
    checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);
    //Set the x and y to south cell
    xPos = startCol;
    yPos = MIN((rows-1), (startRow+1));
    checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);
    //Set the x and y to west cell
    xPos = MAX(0, (startCol-1));
    yPos = startRow;
    checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);
    //Set the x and y to east cell
    xPos = MIN((columns-1), (startCol+1));
    yPos = startRow;
    checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);    

    if(conn == 8){
        //Set the x and y to north-west cell
        int xPos = MAX(0, (startCol-1));
        int yPos = MAX(0, (startRow-1));
        checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);
        //Set the x and y to south-east cell
        xPos = MIN((columns-1), (startCol+1));
        yPos = MIN((rows-1), (startRow+1));
        checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);
        //Set the x and y to north-east cell
        xPos = MIN((columns-1), (startCol+1));
        yPos = MAX(0, (startRow-1));
        checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);
        //Set the x and y to south-west cell
        xPos = MAX(0, (startCol-1));
        yPos = MIN((rows-1), (startRow+1));
        checkCell(yPos, xPos, rows, columns, startRow, startCol, conn, grid_data);    

    }
}