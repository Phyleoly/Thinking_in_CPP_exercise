#include <iostream>
class ClassB {
public:
    void funcB() {
        std::cout << "Function B in ClassB is called." << std::endl;
    }
};

class ClassA {
public:
    void funcA(ClassB* objB) {
        std::cout << "Function A in ClassA is called." << std::endl;
        objB->funcB();
    }
};

int main() {
    ClassA objA;
    ClassB objB;

    objA.funcA(&objB);

    return 0;
}