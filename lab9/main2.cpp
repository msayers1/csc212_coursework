#include "rbtree.h"
#include <iostream>
int main(){
        RBTree t1;
        //std::ostringstream oss;
        t1.insert(20);
        t1.insert(10);
        t1.insert(30);
        t1.insert(5);
        t1.insert(4);
        t1.insert(1);
        t1.insert(6);
        t1.insert(24);
        t1.insert(52);
        t1.insert(28);
        t1.insert(13);

        t1.preorder();

}
