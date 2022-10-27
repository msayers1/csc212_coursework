#include "Queue.h"
#include <iostream>

Queue::Queue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}



void Queue::queue(int data){
    //Simply create a new node, assign its ‘next’ to head, and assign head to the new node!
    // This will work, but its a bit clunky. We have 4 assignments instead of the 2 by using the other constructor!
    // Node* temp = new Node();
    // temp->data = data;
    // temp->next = this->head;

    // Much better implementation, only 2 assignments made & 1 line of code!
    
    Node* temp = new Node(data, nullptr);
    if(_size == 0){
        this->head = temp;
        this->tail = temp;
    } else if (_size == 1) {
        this->head->next = temp;
        this->tail = temp;

    } else {
        this->tail->next = temp;
        this->tail = temp;
    }
    this->_size++;
}

int Queue::dequeue(){
    Node* temp = this->head;
    this->head = this->head->next;
    this->_size--;
    return temp->data;
}

int Queue::peek(){
    return this->head->data;
}

bool Queue::contains(int data){
    // Start temp pointer at head
    Node* temp = this->head;

    // Traverse Linked List until we arrive at the end OR we find 'data'
    while(temp != nullptr && temp->data != data){
        temp = temp->next;
    }

    // Check if we stopped looping because we found 'data'
    if(temp){
        return true;
    }

    // We reached the end of the list & did not find 'data'
    return false;
}

int Queue::size(){
    return this->_size;
}

std::string Queue::to_string(){
    std::string str = "";

    Node* temp = this->head;

    while(temp != nullptr){
        str += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    return str;
}