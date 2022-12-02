#include "rbtree.h"
#include <iostream>
int main(){
        RBTree t1;
        //std::ostringstream oss;
        t1.insert(10);
        t1.insert(7);
        t1.insert(15);
        t1.insert(12);
        t1.insert(13);
        t1.insert(4);
        t1.insert(8);
        t1.insert(1);
        t1.insert(19);
        t1.insert(20);
        t1.insert(5);

        t1.postorder();

}
