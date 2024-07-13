#include <iostream>

class A {
public:
    virtual void funcA() {
        std::cout << "A::funcA()" << std::endl;
    }
};

class B {
public:
    virtual void funcB() {
        std::cout << "B::funcB()" << std::endl;
    }
};

class C : public A, public B {
public:
    void funcC() {
        std::cout << "C::funcC()" << std::endl;
    }
};

int main() {
    C obj;

    obj.funcA();
    obj.funcB();
    obj.funcC();

    return 0;
}