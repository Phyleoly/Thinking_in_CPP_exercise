#include <iostream>

class MyClass {
private:
    static double val1;
    static long val2;
public:
    static void print() {
        std::cout << val1 << std::endl << val2 << std::endl;
    }
};

double MyClass::val1 = 3.14f;
long MyClass::val2 = 3;

int main() {
    MyClass::print();

    return 0;
}