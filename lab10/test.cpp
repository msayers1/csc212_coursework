#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hashtable.h"
#include <iostream>

TEST_CASE("Constructor") {
    HashTable h(7);
}

TEST_CASE("Destructor") {
    HashTable *h = new HashTable(7);
    delete h;
}

TEST_CASE("Hash Table") {
    SUBCASE("Linear Insert"){
        HashTable h(7);
        std::ostringstream oss;
        h.Insert(45);
        h.Insert(28);
        h.Insert(33);
        h.Insert(13);
        h.Insert(54);
        h.Insert(32);
        h.Insert(22);

        h.Access(22, oss);
        h.Access(32, oss);
        h.Access(54, oss);
        h.Access(13, oss);
        h.Access(28, oss);
        h.Access(54, oss);
        h.Access(22, oss);
        
        REQUIRE(oss.str() == "22, 32, 54, 13, 28, 54, 22, ");            
    }

}