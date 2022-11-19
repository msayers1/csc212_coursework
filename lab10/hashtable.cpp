#include "hashtable.h"
#include <cstring>
#include <iostream>


        HashTable::HashTable(int size){
            this->size = size;
            this->count = 0;
            this->table = new std::vector<int>(size, 0);
        };
        

        bool HashTable::Insert(int value){
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

                int temp = value + 1;
                key = temp % size;
                //std::cout << temp << "/" << ((*this->table)[key] != 0) << "/" << (*this->table)[key] << std::endl; 
                while((*this->table)[key] != 0){
                    //std::cout << value << "/" << temp << "/" << key << "/" << (*this->table)[key] << std::endl; 
                    temp = temp + 1;
                    //std::cout << value << "/") << temp << "/" << key << "/" << (*this->table)[key] << std::endl; 
                    key = temp % size;
                }
                (*this->table)[key] = value;
            }
                
            this->count++;
            return true;
        };

        int HashTable::Access(int value){
            int size = this->size;
            int output = 0;
            int key = value % size;
            if((*this->table)[key] == value){
                output = (*this->table)[key];
                //std::cout << (*this->table)[key] << std::endl; 
            } else {
                int temp = value + 1;
                while((*this->table)[key] != value){
                    temp++;
                    key = temp % size;
                }
                output = (*this->table)[key];
                //std::cout << (*this->table)[key] << std::endl; 
            }
            return output;
            //std::cout << (*this->table)[key] << std::endl; 
        };