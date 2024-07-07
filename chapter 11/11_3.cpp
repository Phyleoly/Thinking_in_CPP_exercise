#include <iostream>

int main() {
    // int& ref1; 

    int x = 5;
    int y = 10;
    int& ref2 = x; 
    std::cout << "ref2 = " << ref2 << std::endl; 

    ref2 = y; 
    std::cout << "ref2 = " << ref2 << ", x = " << x << std::endl; 

    int* ptr = nullptr;
    int& ref3 = *ptr; 
    std::cout << "ref3 = " << ref3 << std::endl; 

    return 0;
}
