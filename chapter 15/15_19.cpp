#include <iostream>

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
};

class Derived : public Base {
public:
    void f() override {
        std::cout << "Derived::f()" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->f();  // Virtual function call
    delete b;
    return 0;
}