#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(){
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}



void PriorityQueue::queue(int data, int priority){
    //Boolean to track the while loop later. 
    bool running = true;
    //Create a temp node to hold the data and priority of the incoming value.
    PriorityNode* temp = new PriorityNode(data, priority);
    //handle no entries so far. 
    if(_size == 0){
        this->head = temp;
        this->tail = temp;
    //handle 1 entry so far. 
    } else if (_size == 1) {
        // Handle if it has the same or lower (in this specific scenario lower priority but higher number)
        if(temp->priority >= this->tail->priority){
            this->head->next = temp;
            temp->prev = this->head;
            this->tail = temp;
        // Handle if it has the higher priority (in this specific scenario higher priority but lower number)
        } else {
            temp->next = this->head;
            this->head = temp;
            this->tail->prev = temp;
        }
    // handle more than 1 entry so far
    } else {
        // Handle if it has the same or lower (in this specific scenario lower priority but higher number) This means it goes on the end (rear). 
        if(temp->priority >= this->tail->priority){
            temp->prev = this->tail;
            this->tail->next = temp;
            this->tail = temp;
        }else {
            // Set the current and previous to know where you are in the queue.  
            PriorityNode* current = this->tail->prev;
            PriorityNode* previous = this->tail;
            while(running == true){
                // Handle if it has the same or lower (in this specific scenario lower priority but higher number) This means it goes on the end (rear). 
                if(temp->priority >= current->priority){
                    current->next = temp;
                    temp->prev = current;
                    previous->prev = temp;
                    temp->next = previous;
                    running = false;
                // Handle if you are at the front of the queue. 
                }else if(current->prev == nullptr){
                    //I wanted to handle a situation where your queue is broken. 
                    if(current != this->head){
                        std::cout << "Your program is broken and your array is in disarray." << std::endl;
                        break;
                    // Handle the beginning of the queue. 
                    } else {
                        this->head->prev = temp;
                        temp->next = this->head;
                        this->head = temp;
                        running = false;
                    }
                //Move one step into the queue. 
                } else {
                    previous = current;
                    current = current->prev;                
                }
            }
        
        }
        
    }
    this->_size++;
}

int PriorityQueue::dequeue(){
    PriorityNode* temp = this->head;
    this->head = this->head->next;
    this->_size--;
    return temp->data;
}

int PriorityQueue::peek(){
    return this->head->data;
}

bool PriorityQueue::contains(int data){
    // Start temp pointer at head
    PriorityNode* temp = this->head;

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

int PriorityQueue::size(){
    return this->_size;
}

std::string PriorityQueue::to_string(){
    std::string str = "";

    PriorityNode* temp = this->head;

    while(temp != nullptr){
        str += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    return str;
}