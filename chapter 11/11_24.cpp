#include <iostream>

class MyClass {
public:
    double data;
    void print() const {
        std::cout << data << std::endl;
    }
};

int main() {
    double MyClass::*ptr1 = &MyClass::data;
    void (MyClass::*ptr2)() const = &MyClass::print;

    MyClass obj;
    MyClass* ptr3 = &obj;

    ptr3->data = 1;
    (ptr3->*ptr2)();

    ptr3->*ptr1 = 2;
    (ptr3->*ptr2)();

    return 0;
}