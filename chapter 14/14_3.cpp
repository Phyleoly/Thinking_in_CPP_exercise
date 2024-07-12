#include <iostream>

class A {
public:
    A() { std::cout << "A construct" << std::endl; }
    ~A() { std::cout << "A destruct" << std::endl; }
};

class B : public A {
public:
    B() { std::cout << "B construct" << std::endl; }
    ~B() { std::cout << "B destruct" << std::endl; }
};

class C : public B {
public:
    C() { std::cout << "C construct" << std::endl; }
    ~C() { std::cout << "C destruct" << std::endl; }
};

int main() {
    C c;

    return 0;
}