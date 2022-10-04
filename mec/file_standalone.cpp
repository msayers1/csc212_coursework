// file.cpp
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>

void ReadFile(std::string filename);

//File::File(Gradebook *gradebook){
int main(){
    //this->gradebook = gradebook;
    std::string filename = "sayers.txt";
    ReadFile(filename);
}

void ReadFile(std::string filename){
    // Opens the file for reading
    std::ifstream file(filename);
    

    // Creates a string to hold each line in temporarily
    std::string str;
   
    // Iterates over the file, storing one line at a time into `str`
    while (getline(file, str)) {
        // Create a temporary 1D Vector of doubles
       
        // Create a stringstream object with our line of integers from the file
        std::istringstream ss(str);
        //initializes the double variables. 
        double id, grade, total_points, weight;
        //initializes the string variables. 
        std::string name, category, course;
        //initializes the boolean variable. 
        bool entered;
        //Places the values in the correct variables. 
        ss >> id >> name >> grade >> total_points >> category >> weight >> course >> entered;
        //test output, will replace with assignment to the class gradebook array. 
        std::cout << id << " " << name << " " <<  grade << " " <<  total_points << " " <<  category << " " <<  weight << " " <<  course << " " <<  entered << std::endl;
    }
};

void SaveFile(std::string filename){
    // Needs the class to finish. 
    // // Open our file with write permissions
    // std::ofstream output_file(file_name);
    // //placeholder for the length property from class. 
    // int length = 18;
    // // Use an i to traverse the grades
    // for(int i = 0; i < length; i++){
    //     output_file << id[i] << " " << name[i] << " " <<  grade[i] << " " <<  total_points[i] << " " <<  category[i] << " " <<  weight[i] << " " <<  course[i] << " " <<  entered[i] << "\n";

    // }
};
    



