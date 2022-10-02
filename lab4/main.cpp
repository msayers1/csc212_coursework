//main.cpptd:
#include <iostream>
#include <stdlib.h>
#include "./node.h"
#include "./linked-list.h"
#include <string>

int main(){
    // Linked_List newList;
    // std::string out = newList.To_string();
    // std::cout << "No data test:" << std::endl;
    // std::cout << out << std::endl;

    Linked_List secondList(10);
    int input = 11;
    secondList.Push_back(input);
    int listSize = secondList.Size();
    std::cout << "Create a new list test:" << std::endl;
    std::cout << listSize << std::endl;

    int input2 = 9;
    secondList.Push_front(input2);
    std::string outstring = secondList.To_string();
    std::cout << "Append Test:" << std::endl;
    std::cout << outstring << std::endl;

    Linked_List ll;
    ll.Push_front(5);

    ll.Push_front(10);
    ll.Push_front(15);
    ll.Push_back(100);

    ll.Push_back(101);

    ll.Push_back(102);


    ll.Insert(20, 4);

std::cout << ll.To_string() << std::endl;

    ll.Delete(101);
    
    std::cout << ll.contains(102) << std::endl;
    std::cout << ll.contains(1092) << std::endl;

    std::cout << ll.Size() << std::endl;

    std::cout << ll.To_string() << std::endl;


}