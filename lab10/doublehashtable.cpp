#include "doublehashtable.h"
#include <cstring>
#include <iostream>

        DoubleHashTable::DoubleHashTable(int size){
            this->size = size;
            this->count = 0;
            this->table = new std::vector<int>(size, 0);
        };
        

        bool DoubleHashTable::Insert(int value){
            if(this->size == this->count){
                std::cout << "Hash Table is full!" << std::endl;
                return false;
            }
            int size = this->size;
            int key = value % size;
            //std::cout << key << "/" << (*this->table)[key] << "/" << ((*this->table)[key] != 0) << std::endl;
            if((*this->table)[key] == 0){
                (*this->table)[key] = value;
            } else {

                int temp = (value % size) + 19;
                key = temp % size;
                int i = 2;
                //std::cout << temp << "/" << ((*this->table)[key] != 0) << "/" << (*this->table)[key] << std::endl; 
                while((*this->table)[key] != 0){
                    //std::cout << value << "/" << temp << "/" << key << "/" << (*this->table)[key] << std::endl; 
                    temp = temp + i * 19;
                    //std::cout << value << "/") << temp << "/" << key << "/" << (*this->table)[key] << std::endl; 
                    key = temp % size;
                    i++;
                }
                (*this->table)[key] = value;
            }
                
            this->count++;
            return true;
        };

        int DoubleHashTable::Access(int value){
            int size = this->size;
            int output = 0;
            int key = value % size;
            if((*this->table)[key] == value){
                output = (*this->table)[key];
                //std::cout << (*this->table)[key] << std::endl; 
            } else {
                int temp = (value % size) + 19;
                key = temp % size;
                int i = 2;
                while((*this->table)[key] != value){
                    temp = temp + i * 19;
                    key = temp % size;
                    i++;
                }
                output = (*this->table)[key];
                //std::cout << (*this->table)[key] << std::endl; 
            }
            return output;
            //std::cout << (*this->table)[key] << std::endl; 
        };