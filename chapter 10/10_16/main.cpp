// main.cpp
#include <iostream>
#include "MyNamespace2.h"

void MyNamespace::function1() {
    std::cout << "Function 1 called" << std::endl;
}

void MyNamespace::function2() {
    std::cout << "Function 2 called" << std::endl;
}

int MyNamespace::add(int a, int b) {
    return a + b;
}

void MyNamespace::function3() {
    std::cout << "Function 3 called" << std::endl;
}

void MyNamespace::function4() {
    std::cout << "Function 4 called" << std::endl;
}

int MyNamespace::subtract(int a, int b) {
    return a - b;
}

int main() {
    namespace MN = MyNamespace;

    MN::function1();
    MN::function2();
    std::cout << "Add 5 + 3: " << MN::add(5, 3) << std::endl;
    MN::function3();
    MN::function4();
    std::cout << "Subtract 5 - 3: " << MN::subtract(5, 3) << std::endl;

    using namespace MyNamespace;

    function1();
    function2();
    std::cout << "Add 10 + 5: " << add(10, 5) << std::endl;
    function3();
    function4();
    std::cout << "Subtract 10 - 5: " << subtract(10, 5) << std::endl;

    return 0;
}