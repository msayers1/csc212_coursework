#include "node.h"

        Node::Node(int data) {
            this->data = data;
            this->next = nullptr;
        };

        Node::Node(int data, Node *next){
            this->data = data;
            this->next = next;
        };