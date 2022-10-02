#include <iostream>
#include <stdlib.h>
#include "node.h"

class Linked_List{
    private:
        Node *head;
        Node *tail;
        int length;
    public:
        Linked_List();
        Linked_List(int data);
        void Push_front(int data);
        //Adds an integer to the front of the list 
        void Push_back(int data);
        //Adds an integer to the end of the list
        void Insert(int data, int index);
        //Adds an integer to the list at a specific index
        void Delete(int value);
        //Searches for & removes a specific element in the list
        bool contains(int value);
        //Returns true if the given value exists in the list. False otherwise.
        int Size();
        //Returns the # of elements in the list
        std::string To_string();
        //Returns all elements in the list concatenated into a single string. The list 5 -> 3 -> 4 -> 2 would return "5 3 4 2"
        
};