#include <iostream>

int main() {
    char str[] = "Hello, world!";

    char* ptr = str;

    *ptr = 'h';  

    std::cout << "Modified string: " << str << std::endl;

    return 0;
}