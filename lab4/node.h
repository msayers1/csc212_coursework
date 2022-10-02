#pragma once
#include <iostream>

class Node{
    private:
        Node *next;
        int data;

    public:
        Node(int data);
        Node(int data, Node *next);
        
    friend class Linked_List; 
};