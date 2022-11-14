#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mymap;

    mymap["dog"] = 7;
    mymap.emplace("cat", 5); // This is the same as mymap["cat"] = 4
    mymap.insert({{"fish", 11}}); // This is the same as mymap["fish"] = 11
    mymap["cat"]++;

    std::cout << mymap["dog"] << std::endl; // Prints 7
    std::cout << mymap["cat"] << std::endl; // Prints 5
    std::cout << mymap["fish"] << std::endl; // Prints 11

}