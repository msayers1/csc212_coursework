#include "Queue.h"
#include "PriorityQueue.h"
#include <iostream>
// Fast Food Orders. 
int main(){
    Queue q;
    int serving;
    q.queue(1);
     std::cout << "Array:" << q.to_string() << std::endl;
    std::cout << "Length:" << q.size() << std::endl;
    q.queue(2);
   
    q.queue(3);

    std::cout << "Who is next?" << q.peek() << std::endl;
    q.queue(4);
    q.queue(5);
    q.queue(6);
    std::cout << "Array:" << q.to_string() << std::endl;
    std::cout << "Length:" << q.size() << std::endl;
    
    std::cout << "Is there a 2? " << q.contains(2) << std::endl;
    std::cout << "Is there a 7? " << q.contains(7) << std::endl;
    std::cout << "Who is next?" << q.peek() << std::endl;
    q.queue(99);
    std::cout << "Array:" << q.to_string() << std::endl;
    std::cout << "Length:" << q.size() << std::endl;
    q.queue(100);
    std::cout << "Array:" << q.to_string() << std::endl;
    std::cout << "Length:" << q.size() << std::endl;

    // Dequeue test
    serving = q.dequeue();
    std::cout << "Serving:" << serving << std::endl;
    std::cout << "Array:" << q.to_string() << std::endl;
    std::cout << "Length:" << q.size() << std::endl;

    // Dequeue test 2
    serving = q.dequeue();
    std::cout << "Serving:" << serving << std::endl;
    std::cout << "Array:" << q.to_string() << std::endl;
    std::cout << "Length:" << q.size() << std::endl;
    std::cout << "Who is next?" << q.peek() << std::endl;
    

    //Priority Queue Testing
    std::cout << "entering the Priority Queue Testing." << std::endl;
    PriorityQueue pq;

    pq.queue(1, 100);

    pq.queue(2, 500);
   
    pq.queue(3, 750);
     std::cout <<  "Array:" << pq.to_string() << std::endl;
    std::cout <<  "Length:" << pq.size() << std::endl;
    std::cout << "Who is next?" << pq.peek() << std::endl;
    pq.queue(4, 900);
    pq.queue(5, 450);
    pq.queue(6, 500);
    std::cout << "Array:" << pq.to_string() << std::endl;
    std::cout << "Length:" << pq.size() << std::endl;
    
    std::cout << "Is there a 2? " << pq.contains(2) << std::endl;
    std::cout << "Is there a 7? " << pq.contains(7) << std::endl;
    std::cout << "Who is next?" << pq.peek() << std::endl;
    pq.queue(99, 300);
    std::cout << "Array:" << pq.to_string() << std::endl;
    std::cout << "Length:" << pq.size() << std::endl;
    pq.queue(100, 200);
    std::cout << "Array:" << pq.to_string() << std::endl;
    std::cout << "Length:" << pq.size() << std::endl;

    // Dequeue test
    serving = pq.dequeue();
    std::cout << "Serving:" << serving << std::endl;
    std::cout << "Array:" << pq.to_string() << std::endl;
    std::cout << "Length:" << pq.size() << std::endl;

    // Dequeue test 2
    serving = pq.dequeue();
    std::cout << "Serving:" << serving << std::endl;
    std::cout << "Array:" << pq.to_string() << std::endl;
    std::cout << "Length:" << pq.size() << std::endl;
    std::cout << "Who is next?" << pq.peek() << std::endl;



}