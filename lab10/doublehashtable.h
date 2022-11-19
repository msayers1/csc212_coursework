#include <vector>
#include <iostream>
#include <ostream>
// Underlying class which will be used to implement the RBTree class.
// I.E. RBTree is made up of RBTNode
class DoubleHashTable
{
    private:
        int size;
        int count;
        std::vector<int>* table;

    public:
        DoubleHashTable(int Size);

        bool Insert(int value);
        int Access(int value);

};
