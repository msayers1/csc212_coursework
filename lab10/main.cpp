#include "hashtable.h"
#include "doublehashtable.h"
#include "chaininghashtable.h"
#include <iostream>
int main(){
        HashTable h(7);
        int output;
        h.Insert(45);
        h.Insert(28);
        h.Insert(33);
        h.Insert(13);
        h.Insert(54);
        h.Insert(32);
        h.Insert(22);

        output = h.Access(22);
        std::cout << output << std::endl;            
        output = h.Access(32);
        std::cout << output << std::endl;            
        output = h.Access(54);
        std::cout << output << std::endl;            
        output = h.Access(13);
        std::cout << output << std::endl;            
        output = h.Access(28);
        std::cout << output << std::endl;            
        output = h.Access(45);
        std::cout << output << std::endl;            
        output = h.Access(33);        
        std::cout << output << std::endl;
        DoubleHashTable h2(7);
        h2.Insert(45);
        h2.Insert(28);
        h2.Insert(33);
        h2.Insert(13);
        h2.Insert(54);
        h2.Insert(32);
        h2.Insert(22);

        output = h2.Access(22);
        std::cout << output << std::endl;            
        output = h2.Access(32);
        std::cout << output << std::endl;            
        output = h2.Access(54);
        std::cout << output << std::endl;            
        output = h2.Access(13);
        std::cout << output << std::endl;            
        output = h2.Access(28);
        std::cout << output << std::endl;            
        output = h2.Access(45);
        std::cout << output << std::endl;            
        output = h2.Access(33);        
        std::cout << output << std::endl;            
        ChainingHashTable h3(7);
        h3.Insert(45);
        h3.Insert(28);
        h3.Insert(33);
        h3.Insert(13);
        h3.Insert(54);
        h3.Insert(32);
        h3.Insert(22);

        output = h3.Access(22);
        std::cout << output << std::endl;            
        output = h3.Access(32);
        std::cout << output << std::endl;            
        output = h3.Access(54);
        std::cout << output << std::endl;            
        output = h3.Access(13);
        std::cout << output << std::endl;            
        output = h3.Access(28);
        std::cout << output << std::endl;            
        output = h3.Access(45);
        std::cout << output << std::endl;            
        output = h3.Access(33);        
        std::cout << output << std::endl;
        


    return 0;
    
}
