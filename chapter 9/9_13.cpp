#include <iostream>

class MyClass {
public:
    void f1() {
        std::cout << "in function f1" << std::endl;
        std::cout << "now use f2" << std::endl;
        f2();
    }
    void f2() {
        std::cout << "in function f2" << std::endl;
    }
};

int main() {
    MyClass myClass;
    myClass.f1();

    return 0;
}