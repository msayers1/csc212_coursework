#include "NodeForPriorityQueue.h"
#include <string>

class PriorityQueue{
    private:
        PriorityNode* head;
        PriorityNode* tail;
        unsigned int _size = 0;

    public:
        PriorityQueue();

        void queue(int data, int priority);
        int dequeue();
        int peek();
        bool contains(int data);
        int size();
        std::string to_string();
};