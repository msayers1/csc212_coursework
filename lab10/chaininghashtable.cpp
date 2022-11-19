#include "chaininghashtable.h"
#include <cstring>
#include <iostream>

        ChainingHashTable::ChainingHashTable(int size){
            this->size = size;
            this->count = 0;
            this->table = new std::vector<std::vector<int>>(size, std::vector<int>(0));
        };
        

        bool ChainingHashTable::Insert(int value){
            int size = this->size;
            int key = value % size;
            (*this->table)[key].push_back(value);
            
                
            return true;
        };

        int ChainingHashTable::Access(int value){
            int size = this->size;
            int output = 0;
            int key = value % size;
            if((*this->table)[key][0] == value){
                output = (*this->table)[key][0];
                //std::cout << (*this->table)[key] << std::endl; 
            } else {
                int i = 1;
                while((*this->table)[key][i] != value){
                    i++;
                }
                output = (*this->table)[key][i];
                //std::cout << (*this->table)[key] << std::endl; 
            }
            return output;
            //std::cout << (*this->table)[key] << std::endl; 
        };