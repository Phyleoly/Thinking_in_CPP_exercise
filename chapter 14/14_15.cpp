#include <iostream>

class MyClass {
public:
    static void f() { std::cout << "MyClass::f()"; }
    static void g() { std::cout << "MyClass::g()"; }
};

class A : public MyClass {
public:
    static void f() { std::cout << "A::f()"; }
};

int main() {
    A::f();
    A::g(); 

    return 0;
}