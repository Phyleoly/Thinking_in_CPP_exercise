#include <iostream>

int main() {
    std::cout << "Size of fundamental data types:" << std::endl;
    std::cout << "================================" << std::endl;

    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of unsigned char: " << sizeof(unsigned char) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "Size of unsigned short: " << sizeof(unsigned short) << " bytes" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "Size of unsigned long: " << sizeof(unsigned long) << " bytes" << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "Size of unsigned long long: " << sizeof(unsigned long long) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    return 0;
}