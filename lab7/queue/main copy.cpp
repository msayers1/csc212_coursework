#include "Queue.h"
#include <iostream>
// Fast Food Orders. 
int main(){
    Queue q;
    int serving;
    q.queue(1);
     std::cout << q.to_string() << std::endl;
    std::cout << q.size() << std::endl;
    q.queue(2);
   
    q.queue(3);

    std::cout << "Who is next?" << q.peek() << std::endl;
    q.queue(4);
    q.queue(5);
    q.queue(6);
    std::cout << q.to_string() << std::endl;
    std::cout << q.size() << std::endl;
    
    std::cout << q.contains(2) << std::endl;
    std::cout << q.contains(7) << std::endl;
    std::cout << "Who is next?" << q.peek() << std::endl;
    q.queue(99);
    std::cout << q.to_string() << std::endl;
    std::cout << q.size() << std::endl;
    q.queue(100);
    std::cout << q.to_string() << std::endl;
    std::cout << q.size() << std::endl;

    // Dequeue test
    serving = q.dequeue();
    std::cout << "Serving:" << serving << std::endl;
    std::cout << q.to_string() << std::endl;
    std::cout << q.size() << std::endl;

    // Dequeue test 2
    serving = q.dequeue();
    std::cout << "Serving:" << serving << std::endl;
    std::cout << q.to_string() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << "Who is next?" << q.peek() << std::endl;
    

}