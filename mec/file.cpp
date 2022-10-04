// file.cpp
#include "file.h"
#include "gradebook.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>

//File::File(Gradebook *gradebook){
File::File(){
    //this->gradebook = gradebook;
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
        double id, grade, total_points, weight;
        std::string name, category, course;
        bool entered;
        ss >> id >> name >> grade >> total_points >> category >> weight >> course >> entered;
        std::cout << id << " " << name << " " <<  grade << " " <<  total_points << " " <<  category << " " <<  weight << " " <<  course << " " <<  entered;
    }
};

void SaveFile(std::string filename){
    // // Open our file with write permissions
    // ofstream output_file(file_name);

    // // Use an iterator to traverse the outer dimension
    // for(vector<vector<double>>::const_iterator i = (*image_data).begin(); i != (*image_data).end(); ++i){
    // // Use an interator to traverse the inner dimention
    // for(vector<double>::const_iterator j = i->begin(); j != i->end(); ++j){
    //     // Output each element to the file with a space at the end
    //     output_file << *j << " ";
    // }
    // // Output a newline symbol to the file
    // output_file << "\n";
    // }
};
    



