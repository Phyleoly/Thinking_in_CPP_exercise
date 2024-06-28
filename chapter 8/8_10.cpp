#include <iostream>

int main() {
    const int val = 10;
    const int* const ptr = &val;
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;

    // *ptr = 20; 
    // ptr++; 
}