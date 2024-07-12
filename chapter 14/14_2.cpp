#include <iostream>

class A {
public:
    A() {
        std::cout << "A constructor" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "B constructor" << std::endl;
    }
};

class C : public A {
public:
    B b;
};

int main() {
    C c;

    return 0;
}