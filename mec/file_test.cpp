//file_test.cpp:
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
#include "file.h"
#include "gradebook.h"


int main(){
    File newFile;
    std::string filename = "sayers.txt";
    newFile.ReadFile(filename);
}