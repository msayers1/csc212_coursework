#include "bst.h"

int main(){
    BSTree t;
    for (int i = 0; i < 100; ++i) {
        std::cout << "Is height equal to i - 1? "  << ((t.height() == i-1)?" True, ":" False, ") << " But height is " << t.height() << "And i is " << i << std::endl;
        t.insert(i);
    }
    BSTree t2;
    for (int i = 100; i > 0; --i) {
        std::cout << "Is height equal to i - 1? "  << ((t2.height() == i-1)?" True, ":" False, ") << " But height is " << t2.height() << "And i is " << i << std::endl;
        t2.insert(i);
    }
    std::cout << "the height is " << t.height() << std::endl;
    std::cout << "Is the height 99?  " << (t.height() == 99) << std::endl;
    return 0;
}
    