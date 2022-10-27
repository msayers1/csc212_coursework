#include "Node.h"
#include <string>

class Queue{
    private:
        Node* head;
        Node* tail;
        unsigned int _size = 0;

    public:
        Queue();

        void queue(int data);
        int dequeue();
        int peek();
        bool contains(int data);
        int size();
        std::string to_string();
};