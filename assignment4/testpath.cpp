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


void ReadFile(std::string file_name, std::vector<std::vector<std::vector<double>>> * grid_data, std::vector<int>* answer);
void outputGrid(std::vector<std::vector<std::vector<double>>> * grid_data);
bool findPath(int rows, int columns, int startRow, int startCol,  std::vector<std::vector<std::vector<double>>> * grid_data, std::vector<int>* answer);

int main(int argc, char* argv[]){
    std::string filename = "./path/simple.txt";
    int rows = 5;
    int columns = 5;
    std::vector <int> answer(6,1);
    answer[0] = -1;
    answer[3] = -1;
    std::vector<std::vector<std::vector<double>>> grid_data;
    ReadFile(filename, &grid_data, &answer);
    
    bool result = findPath((rows-1),(columns-1),(answer[1]-1),(answer[2]-1), &grid_data, &answer);
        
    std::cout << "Max" << answer[0] << " at y location" << answer[1] << " by x location " << answer[2] << " and " << "min" << answer[3] << " at y location " << answer[4] << " by x location " << answer[5] << "there is a path:" << (result?"yes":"no") << std::endl;
    //std::cout << counter << std::endl; 
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
void CheckValue(int value, std::vector<int>* answer, int x, int y){
    // std::cout << "Max" << (*answer)[0] << " at location " << (*answer)[1] << " by location " << (*answer)[2] << " and " << "min" << (*answer)[3] << " at location " << (*answer)[4] << " by location " << (*answer)[5] << std::endl;
    
    if((*answer)[0] == -1){
        (*answer)[0] = value;
        (*answer)[1] = y;
        (*answer)[2] = x;
    }else if (value > (*answer)[0]){
        (*answer)[0] = value;
        (*answer)[1] = y;
        (*answer)[2] = x;
    }

    if((*answer)[3] == -1){
        (*answer)[3] = value;
        (*answer)[4] = y;
        (*answer)[5] = x;
    }else if (value < (*answer)[3]){
        (*answer)[3] = value;
        (*answer)[4] = y;
        (*answer)[5] = x;
    }
}

void ReadFile(std::string file_name, std::vector<std::vector<std::vector<double>>> * grid_data, std::vector<int>* answer){
    // Opens the file for reading
    std::ifstream file(file_name);
    std::vector<double> cell;
    // Creates a string to hold each line in temporarily
    std::string str;
    int x = 1;
    int maxX = 1;
    int y = 1;
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
            CheckValue(token, answer, x, y);    
            cell.push_back(token);
            cell.push_back(0);
            new_row.push_back(cell);
            cell.clear();
            x++;
        }
        
        // The line is empty, push our completed row into our 2D vector
        if(new_row.size() != 0){
            grid_data->push_back(new_row);
            y++;
            maxX=MAX(x,maxX);
            x=1;
        }     
    }
    std::cout << y << " by " << maxX << std::endl;
}

bool checkCell(int yPos, int xPos, int rows, int columns, int startRow, int startCol, std::vector<std::vector<std::vector<double>>> * grid_data, std::vector<int>* answer){
    if((*grid_data)[yPos][xPos][1] == 0 && (*grid_data)[yPos][xPos][0] <= (*grid_data)[startRow][startCol][0] ){
        (*grid_data)[yPos][xPos][1] = 1;
        if(findPath(rows, columns, yPos, xPos, grid_data, answer))return true;
    } else {
        return false;
    }
}
    
    

bool findPath( int rows, int columns, int startRow, int startCol, std::vector<std::vector<std::vector<double>>> * grid_data, std::vector<int>* answer){
    if(((*answer)[4]-1) == startRow && ((*answer)[5]-1) == startCol){
        return true;
    }

    //Set the x and y to north cell
    int xPos = startCol;
    int yPos = MAX(0, (startRow-1));
    if(checkCell(yPos, xPos, rows, columns, startRow, startCol, grid_data, answer))return true;
    //Set the x and y to south cell
    xPos = startCol;
    yPos = MIN((rows), (startRow+1));
    if(checkCell(yPos, xPos, rows, columns, startRow, startCol, grid_data, answer))return true;
    //Set the x and y to west cell
    xPos = MAX(0, (startCol-1));
    yPos = startRow;
    if(checkCell(yPos, xPos, rows, columns, startRow, startCol, grid_data, answer))return true;
    //Set the x and y to east cell
    xPos = MIN((columns), (startCol+1));
    yPos = startRow;
    if(checkCell(yPos, xPos, rows, columns, startRow, startCol, grid_data, answer))return true;
}