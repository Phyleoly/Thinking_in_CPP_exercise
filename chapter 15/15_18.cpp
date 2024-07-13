#include <iostream>

class A {
    int a;
};

class B : public A {
    int b;
};

void f(A a) {
    std::cout << sizeof(a) << std::endl;
}

int main() {
    B b;
    std::cout << sizeof(b) << std::endl;
    f(b);

    return 0;
}