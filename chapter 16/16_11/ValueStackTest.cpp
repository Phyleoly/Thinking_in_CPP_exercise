#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<int> intStack;

    for (int i = 0; i < 120; ++i) {
        intStack.push_back(i);
    }

    std::cout << "Popping elements from intStack: ";
    while (!intStack.empty()) {
        std::cout << intStack.back() << " "; 
        intStack.pop_back();
    }
    std::cout << std::endl;

    std::vector<std::string> stringStack;

    stringStack.push_back("Hello");
    stringStack.push_back("World");
    stringStack.push_back("!");

    std::cout << "Size of stringStack: " << stringStack.size() << std::endl; 

    if (!stringStack.empty()) {
        std::cout << "Top element: " << stringStack.back() << std::endl; 
    }

    std::cout << "Popping strings: ";
    while (!stringStack.empty()) {
        std::cout << stringStack.back() << " "; 
        stringStack.pop_back();
    }
    std::cout << std::endl;

    return 0;
}