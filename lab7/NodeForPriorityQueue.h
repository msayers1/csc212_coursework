class PriorityNode{
    private:
        int data;
        PriorityNode* next;
        PriorityNode* prev;
        int priority;

    public:
        // Not used. Implemented anyway.
        PriorityNode();
        PriorityNode(int data, int priority);
        PriorityNode(int data, int priority, PriorityNode* next);
        PriorityNode(int data, int priority, PriorityNode* next, PriorityNode* prev);

        friend class PriorityQueue;
};