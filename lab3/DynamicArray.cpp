#include "DynamicArray.h"
#include <cstring>
#include <iostream>

DynamicArray::DynamicArray()
    : m_length(0), m_capacity(0), m_scaling_factor(2.0), m_data(nullptr) { 
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    this->m_length = 0;
    this->m_scaling_factor = scaling_factor;
    this->m_capacity = capacity;
    this->m_data = new int[capacity];

}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    this->m_length = length;
    this->m_capacity = length;
    this->m_scaling_factor = scaling_factor;
    int* newArray = new int[length];
    for(unsigned int i = 0; i < length; i++){
        newArray[i] = default_value;
    }
    this->m_data = newArray;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::getLength() {
    return m_length;
}

unsigned int DynamicArray::getCapacity() {
    return m_capacity;
}

double DynamicArray::getScalingFactor() {
    return m_scaling_factor;
}

void DynamicArray::setScalingFactor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::toString() {
    std::string str("{");
    for (unsigned int i = 0 ; i < m_length ; i++) {
        str.append(std::to_string(m_data[i]));
        if (i < m_length - 1) {
            str.push_back(' ');
        }
    }
    str.push_back('}');
    // std::cout << "Your dynamic array is" << str << std::endl;
    return str;
}

// bool DynamicArray::findFirstOfWithStartingPoint(int value, unsigned int *index, unsigned int startingPoint = 0) {
//     bool found = false;
//     unsigned int startingPoint = *index;
//     for(unsigned int i = startingPoint; i < m_length; i++){
//         if(value == m_data[i]){
//             found = true;
//             i = m_length;
//         }
//     }
        
//     return found;
// }

// bool DynamicArray::findLastOfWithStartingPoint(int value, unsigned int *index, unsigned int startingPoint) {
//     bool found = false;
//     for(unsigned int i = startingPoint; i > 0; i--){
//         int needle = m_data[i];
//         if(value == needle){
//             found = true;
//         }
//     }
        
//     return found;
// }


bool DynamicArray::findFirstOf(int value, unsigned int *index) {
    bool found = false;
    for(unsigned int i = 0; i < m_length; i++){
        if(value == m_data[i]){
            found = true;
            *index = i;
            i = m_length;
        }
    }
        
    return found;
}

bool DynamicArray::findLastOf(int value, unsigned int *index) {
    bool found = false;
        for(unsigned int i = 0; i < m_length; i++){
        if(value == m_data[i]){
            found = true;
            *index = i;
        }
    }   
    return found;
}

void DynamicArray::append(int value) {
    if(m_capacity == m_length){
        //std::cout << "Trying to put " << value << " in array with length " << m_length << std::endl;
        //create an array with capacity * scaling factor
        int newCapacity = m_capacity * m_scaling_factor;
        int* newArray = new int[newCapacity];
        //copy array to new array
        for(unsigned int i = 0; i < m_length; i++){
            newArray[i] = m_data[i];
        }
        //append the value
        newArray[m_length] = value;
        //insert new Array to data spot
        delete[] this->m_data;
        this->m_data = newArray;
        this->m_capacity = newCapacity;
        this->m_length++;
    } else {
        // std::cout << "Trying to put " << value << " in array with length " << m_length << std::endl;
        //append the value
        m_data[m_length] = value;
        //increment length
        this->m_length++;
    }        
}

void DynamicArray::prepend(int value) {
    if(m_capacity == m_length){
        // std::cout << "Trying to put " << value << " in array with length " << m_length << std::endl;
        //create an array with capacity * scaling factor
        int newCapacity = m_capacity * m_scaling_factor;
        int* newArray = new int[newCapacity];
        //copy array to new array
        //prepend the value
        newArray[0] = value;
        for(unsigned int i = 1; i < m_length; i++){
            newArray[i] = m_data[i-1];
        }

        //insert new Array to data spot
        delete[] this->m_data;
        this->m_data = newArray;
        this->m_capacity = newCapacity;
        this->m_length++;
    } else {
        // std::cout << "Trying to put " << value << " in array with length " << m_length << std::endl;
        //create a new array 
        int* newArray = new int[m_capacity];
        //copy array to new array

        //prepend the value
        newArray[0] = value;
        for(unsigned int i = 1; i < m_length; i++){
            newArray[i] = m_data[i-1];
        }
        //append the value
        newArray[m_length] = value;
        //insert new Array to data spot
        delete[] this->m_data;
        this->m_data = newArray;
        
        //increment length
        this->m_length++;
    }        
}

void DynamicArray::removeLast() {
    //increment length
    this->m_length--;
}

void DynamicArray::removeFirst() {
    //create a new array 
    int* newArray = new int[m_capacity];
    //copy array to new array not copying the last

    for(unsigned int i = 1; i < m_length; i++){
        newArray[i-1] = m_data[i];
    }
    //insert new Array to data spot
    delete[] this->m_data;
    this->m_data = newArray;
    
    //increment length
    this->m_length--;
}

void DynamicArray::clear() {
    //create a new array 
    int* newArray = new int[m_capacity];

    //insert new Array to data spot
    delete[] this->m_data;
    this->m_data = newArray;
    
    //increment length
    this->m_length = 0;
}

int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}