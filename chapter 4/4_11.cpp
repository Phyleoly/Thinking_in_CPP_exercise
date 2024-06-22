#include <iostream>


int main() {
    #ifdef MY_MACRO
        std::cout << "MY_MACRO is defined." << std::endl;
    #else
        std::cout << "MY_MACRO is not defined." << std::endl;
    #endif

    return 0;
}