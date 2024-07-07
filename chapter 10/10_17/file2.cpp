// file2.cpp
#include "UnnamedNamespace.h"
#include <iostream>

namespace {
    void function1() {
        std::cout << "Function 1 from file2.cpp" << std::endl;
    }

    void function2() {
        std::cout << "Function 2 from file2.cpp" << std::endl;
    }
}

int main() {
    function1();
    function2();
    return 0;
}