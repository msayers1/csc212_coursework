class PriorityNode{
    private:
        int data;
        PriorityNode* next;
        int priority;

    public:
        // Not used. Implemented anyway.
        PriorityNode();
        PriorityNode(int data, int priority);
        PriorityNode(int data, int priority, PriorityNode* next);

        friend class Queue;
};