#include <iostream>

int main() {
    const long arr[] = {10, 20, 30, 40, 50}; 
    const long* ptr1 = arr; // 指向const long的指针
    const long* const ptr2 = arr; // 指向const long的常量指针

    std::cout << "Using ptr1:" << std::endl;
    std::cout << "Initial value: " << *ptr1 << std::endl;

    ptr1++;
    std::cout << "After increment: " << *ptr1 << std::endl;
    ptr1--;
    std::cout << "After decrement: " << *ptr1 << std::endl;

    std::cout << "\nUsing ptr2:" << std::endl;
    std::cout << "Initial value: " << *ptr2 << std::endl;

    return 0;
}
