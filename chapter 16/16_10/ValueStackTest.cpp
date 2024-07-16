#include <iostream>
#include "ValueStack.h"

int main() {
    Stack<int> intStack;

    for (int i = 0; i < 120; ++i) {
        intStack.push(i);
    }

    std::cout << "Size of intStack: " << intStack.size() << std::endl; 

    std::cout << "Popping elements from intStack: ";
    while (!intStack.empty()) {
        std::cout << intStack.pop() << " "; 
    }
    std::cout << std::endl;

    Stack<std::string> stringStack;

    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("!");

    std::cout << "Size of stringStack: " << stringStack.size() << std::endl; 

    std::cout << "Top element: " << stringStack.peek() << std::endl; 

    std::cout << "Popping strings: ";
    while (!stringStack.empty()) {
        std::cout << stringStack.pop() << " "; 
    }
    std::cout << std::endl;

    return 0;
}