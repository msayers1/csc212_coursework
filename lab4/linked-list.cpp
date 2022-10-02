#include <iostream>
#include "./linked-list.h"
#include <stdlib.h>
#include <string>

    Linked_List::Linked_List(){
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    };
    Linked_List::Linked_List(int data){
        Node * newNodePointer = new Node(data);
        this->head = newNodePointer;
        this->tail = newNodePointer;
        this->length = 1;
    };
    void Linked_List::Push_front(int data){
        Node *newNode = new Node(data, this->head);
        this->head = newNode;
        if(this->length){
            this->length = this->length + 1;
        } else {
            this->length = 1;
            this->tail = newNode;
        }
        return;
    };
    //Adds an integer to the front of the list 
    void Linked_List::Push_back(int data){
        Node *newNode = new Node(data);
        Node *tailNode = this->tail;
        tailNode->next = newNode;
        this->tail = newNode;
        this->length = this->length + 1;
        return;
    };
    //Adds an integer to the end of the list
    void Linked_List::Insert(int data, int index){
        if(!this->head){    // this->head == nullptr
            this->head = new Node(data);
        }else if(index == 0){
            this->Push_front(data);
            return;
        }else if(this->length < index){
            this->Push_back(data);
            return;
        }else{
            Node* tmp = this->head;
            while(index > 1){
                tmp = tmp->next;
                index--;
            }
            Node* tmp2 = new Node(data, tmp->next);
            //tmp2->next = tmp->next;
            tmp->next = tmp2;
        }
        this->length++;
        return;
    }
        
    //Adds an integer to the list at a specific index
    void Linked_List::Delete(int value){
        Node* tmp = this->head;
        Node* prev = nullptr;

        while(tmp != nullptr && tmp->data != value){
            prev = tmp;
            tmp = tmp->next;
        }

    if(tmp != nullptr){
        while(tmp != nullptr){
            prev->next = tmp->next;
            // Without this, the Node destructor will delete
            // every element in the list after 'temp'
            tmp->next = nullptr;
            delete tmp;

            this->length--;
            tmp = prev->next;
        }
    }else{
        std::cout << value << " does not exist!" << std::endl;
    }
        // Node *current, *previous;
        // int found = 0;
        // previous = nullptr;
        // current = this->head;
        // while(found == 0 || (current->next == nullptr)){
        //     if(current->data == value){
        //         found = 1;
        //         previous->next = current->next;
        //     } else {
        //         current = current->next;
        //     }
        // }
        // this->length = this->length - 1;
        // return;
    };
    //Searches for & removes a specific element in the list
    bool Linked_List::contains(int value){
        Node *current;
        bool found = false;
        current = this->head;
        while(found == true || (current->next == nullptr)){
            if(current->data == value){
                found = true;
            } else {
                current = current->next;
            }

        }
        return found;
    };
    //Returns true if the given value exists in the list. False otherwise.
    int Linked_List::Size(){
        return this->length;
    };
    //Returns the # of elements in the list
    std::string Linked_List::To_string(){
        std::string output;
        Node *current = this->head;
        while(current != nullptr){
            output += std::to_string(current->data) + " ";
            current = current->next;
        }
        return output;
    };
    //Returns all elements in the list concatenated into a single string. The list 5 -> 3 -> 4 -> 2 would return "5 3 4 2"