//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

double PixalMax;
double PixalMin; 

//Algorithm to find a median
double findMedian(vector<double> range){
    size_t size = range.size();

    if (size == 0)
    {
        return 0;  // Undefined, really.
    }
    else
    {
        sort(range.begin(), range.end());
        if (size % 2 == 0)
        {
        return (range[size / 2 - 1] + range[size / 2]) / 2;
        }
        else 
        {
        return range[size / 2];
        }
    }

}

double findMean(vector<double> range){
    float sum = 0.0;
    int i;
    double size = range.size();
    for(i = 0; i < size; ++i) {
        sum += range[i];
    }

    return(sum / size);
}

double findStandardDeviation(vector<double> range){
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;
    double size = range.size();
    for(i = 0; i < size; ++i) {
        sum += range[i];
    }

    mean = sum / size;

    for(i = 0; i < size; ++i) {
        standardDeviation += pow(range[i] - mean, 2);
    }
    //double n_minus_1 = size - 1;
    //return sqrt(standardDeviation / n_minus_1);
    return sqrt(standardDeviation / size);
}

void WriteFile(string file_name, vector<vector<double>> * const image_data){
    // Open our file with write permissions
    ofstream output_file(file_name);

    // Use an iterator to traverse the outer dimension
    for(vector<vector<double>>::const_iterator i = (*image_data).begin(); i != (*image_data).end(); ++i){
        // Use an interator to traverse the inner dimention
        for(vector<double>::const_iterator j = i->begin(); j != i->end(); ++j){
            // Output each element to the file with a space at the end
            output_file << *j << " ";
        }
        // Output a newline symbol to the file
        output_file << "\n";
    }
}

 void ReadFile(string file_name, vector<vector<double>> * image_data, vector<double> * all_numbers){
    // Opens the file for reading
    ifstream file(file_name);
    

    // Creates a string to hold each line in temporarily
    string str;
   
    //int counter = 0;
    // Iterates over the file, storing one line at a time into `str`
    while (getline(file, str)) {
        // Create a temporary 1D Vector of doubles
       vector<double> new_row;

       // Create a stringstream object with our line of integers from the file
       istringstream ss(str);

       // Create a double that will hold our extracted value from the string
       double token;

        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
            all_numbers->push_back(token);
            // PixalMax = max(PixalMax, token);
            // PixalMin = min(PixalMin, token);
        }

        // The line is empty, push our completed row into our 2D vector
        if(new_row.size() != 0){
            image_data->push_back(new_row);
        } 
        
    }
}


double getNeighborhoodThreshold(vector<vector<double>> * input_image_data, double neighborhood, double row, double column, int num_rows, int num_cols){
    vector<double> neighborhood_data;

    int starting_row = row - neighborhood;
    int ending_row = row + neighborhood;
    if(starting_row < 0){
        starting_row = 0;
    }
    if(ending_row > (num_rows - 1) ){
        ending_row = (num_rows - 1);
    }
    int starting_column = column - neighborhood;
    int ending_column = column + neighborhood;
    if(starting_column < 0){
        starting_column = 0;
    }
    if(ending_column > (num_cols -1) ){
        ending_column = (num_cols -1);
    }

    for(int i = starting_row; i < (ending_row + 1); ++i){
        for(int j = starting_column; j < (ending_column + 1); ++j){
            neighborhood_data.push_back((*input_image_data)[i][j]);
        }
    }
    
    double k_constant = .2;
    double R = 0.5 * ( PixalMax - PixalMin);
    double standard_deviation, mean;
    mean = findMean(neighborhood_data);
    standard_deviation = findStandardDeviation(neighborhood_data);     
    double threshold = mean * ( 1 + k_constant * (( standard_deviation / R ) - 1));
    return threshold;

}

void localThresholdBinarization(vector<vector<double>> * const input_image_data, vector<vector<double>> * output_image_data, double neigborhood) {
    int num_rows = (*input_image_data).size();
    // Use an row key to keep track of row while traversing the outer dimension
    for(int row_key = 0; row_key != num_rows; ++row_key){
        // Use row key to keep track of row while traversing the inner dimention
        vector<double> new_row;
        vector<double> input_row;
        
        int num_cols = (*input_image_data)[row_key].size();
         for(int column_key = 0; column_key != num_cols; ++column_key){
            double threshold = getNeighborhoodThreshold(input_image_data, neigborhood, row_key, column_key, num_rows, num_cols);
            //if(row_key == 377) 
            cout << column_key << " by " << row_key << " : " << (*input_image_data)[row_key][column_key] << "and threshold" << threshold << endl;
            if((*input_image_data)[row_key][column_key] < threshold ){
                new_row.push_back(0);
            } else {
                new_row.push_back(255);
            }
        }
        output_image_data->push_back(new_row);
    } 
}

void globalThresholdBinarization(vector<vector<double>> * const input_image_data, vector<vector<double>> * output_image_data, double threshold) {
    // Use an iterator to traverse the outer dimension
    for(vector<vector<double>>::const_iterator row_data = (*input_image_data).begin(); row_data != (*input_image_data).end(); ++row_data){
        vector<double> new_row;
        // Use an interator to traverse the inner dimention
        for(vector<double>::const_iterator cell_data = row_data->begin(); cell_data != row_data->end(); ++cell_data){
            if(*cell_data < threshold){
                new_row.push_back(0);
            } else {
                new_row.push_back(255);
            }
        }
        output_image_data->push_back(new_row);
    } 
}



int main (int argc, char* argv[]){
    //Pull in the type global vs local
    string type = argv[1];
    //Pull in the input file name
    string in_fname = argv[2];
    //Pull in the output filename
    string out_fname = argv[3];
    double neighborhood = 0;
    if (argc > 4) {
        //if there is argv[4] pull in the size of the neighborhood.
        int size = stoi(argv[4]);
        //Logic to convert square size to number of pixels around the pixel. 
        if(size < 2){
            neighborhood = 1;
        } if (size % 2 == 0){
            neighborhood = ( size ) / 2;
        } else {
            neighborhood = ( size - 1 ) / 2;        
        }
    }

    //Initialize a 2d vector for the input and output. 
    vector<vector<double>> input_image_data;
    vector<vector<double>> output_image_data;
    //Initialize a 1d vector to hold all numbers
    vector<double> all_numbers;
    //read the file
    ReadFile(in_fname, &input_image_data, &all_numbers);
    PixalMin = *min_element (all_numbers.begin(), all_numbers.end());

    PixalMax = *max_element (all_numbers.begin(), all_numbers.end());
    // cout << min << " and " << max << " are min and max.";
    // cout << PixalMin << " and " << PixalMax << " are Pixal min and max.";
    
    if(type == "local"){
        localThresholdBinarization(&input_image_data, &output_image_data, neighborhood);
    } else {
        double threshold = findMedian(all_numbers);
        globalThresholdBinarization(&input_image_data, &output_image_data, threshold);
    }
    //write the file
    WriteFile(out_fname, &output_image_data);

}