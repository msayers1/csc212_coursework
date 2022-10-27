#include "NodeForPriorityQueue.h"

PriorityNode::PriorityNode(){
    this->data = 0;
    this->next = nullptr;
}

PriorityNode::PriorityNode(int data, int priority){
    this->data = data;
    this->priority = priority;
    this->next = nullptr;
}

PriorityNode::PriorityNode(int data, int priority, PriorityNode* next){
    this->data = data;
    this->priority = priority;
    this->next = next;
}