// file.h
#pragma once
#include <iostream>
#include "gradebook.h"
#include <string>
class File{
    private:
        //Gradebook *gradebook = new Gradebook();

    public:
        //File(Gradebook *gradebook);
        File();
            void ReadFile(std::string filename);
            void SaveFile(std::string filename);
};