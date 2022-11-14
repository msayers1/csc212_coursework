#include "rbtree.h"
#include <iostream>
int main(){
        RBTree t1;
        //std::ostringstream oss;
        t1.insert(7);
        t1.insert(6);
        t1.insert(5);
        t1.insert(4);
        t1.insert(3);
        t1.insert(2);
        t1.insert(1);

        t1.postorder();


        RBTree t2;
        //std::ostringstream oss;
        t2.insert(5);
        t2.insert(2);
        t2.insert(3);
        t2.insert(6);
        t2.insert(4);
        t2.insert(7);

        t2.insert(1);
        
        t2.postorder();
        // std::cout << oss << std::endl;
}
        

//     SUBCASE("Reversed Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(7);
//         t.insert(6);
//         t.insert(5);
//         t.insert(4);
//         t.insert(3);
//         t.insert(2);
//         t.insert(1);

//         t.postorder(oss);
//         REQUIRE(oss.str() == "1:0, 3:0, 2:0, 5:0, 7:0, 6:0, 4:0, \n");
//     }
//     SUBCASE("Random Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(5);
//         t.insert(2);
//         t.insert(3);
//         t.insert(6);
//         t.insert(4);
//         t.insert(1);
//         t.insert(7);

//         t.postorder(oss);
//         REQUIRE(oss.str() == "1:1, 2:0, 4:0, 3:1, 6:1, 7:0, 5:0, \n");
//     }

// }

// TEST_CASE("Inorder") {
//     SUBCASE("Ordered Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(1);
//         t.insert(2);
//         t.insert(3);
//         t.insert(4);
//         t.insert(5);
//         t.insert(6);
//         t.insert(7);

//         t.inorder(oss);
//         REQUIRE(oss.str() == "1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, \n");
//     }
//     SUBCASE("Reversed Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(7);
//         t.insert(6);
//         t.insert(5);
//         t.insert(4);
//         t.insert(3);
//         t.insert(2);
//         t.insert(1);

//         t.inorder(oss);
//         REQUIRE(oss.str() == "1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, \n");
//     }
//     SUBCASE("Random Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(5);
//         t.insert(2);
//         t.insert(3);
//         t.insert(6);
//         t.insert(4);
//         t.insert(1);
//         t.insert(7);

//         t.inorder(oss);
//         REQUIRE(oss.str() == "1:1, 2:0, 3:1, 4:0, 5:0, 6:1, 7:0, \n");
//     }

// }

// TEST_CASE("Preorder") {
//     SUBCASE("Ordered Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(1);
//         t.insert(2);
//         t.insert(3);
//         t.insert(4);
//         t.insert(5);
//         t.insert(6);
//         t.insert(7);

//         t.preorder(oss);
//         REQUIRE(oss.str() == "4:0, 2:0, 1:0, 3:0, 6:0, 5:0, 7:0, \n");
//     }
//     SUBCASE("Reversed Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(7);
//         t.insert(6);
//         t.insert(5);
//         t.insert(4);
//         t.insert(3);
//         t.insert(2);
//         t.insert(1);

//         t.preorder(oss);
//         REQUIRE(oss.str() == "4:0, 2:0, 1:0, 3:0, 6:0, 5:0, 7:0, \n");
//     }
//     SUBCASE("Random Input"){
//         RBTree t;
//         std::ostringstream oss;
//         t.insert(5);
//         t.insert(2);
//         t.insert(3);
//         t.insert(6);
//         t.insert(4);
//         t.insert(1);
//         t.insert(7);

//         t.preorder(oss);
//         REQUIRE(oss.str() == "5:0, 3:1, 2:0, 1:1, 4:0, 7:0, 6:1, \n");
//     }
// }

// TEST_CASE("Height") {
//    RBTree t;
//    REQUIRE(t.height() == -1);
//    t.insert(12);
//    REQUIRE(t.height() == 0);
//    t.insert(5);
//    t.insert(15);
//    REQUIRE(t.height() == 1);
//    t.insert(3);
//    t.insert(10);
//    REQUIRE(t.height() == 2);
//    t.insert(4);
//    t.insert(13);
//    t.insert(17);
//    REQUIRE(t.height() == 3);
//    t.insert(11);
//    t.insert(6);
//    t.insert(8);
//    REQUIRE(t.height() == 4);
// }