#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "in construction" << std::endl;
    }

    ~MyClass() {
        std::cout << "in destruction" << std::endl;
        exit(0);
    }
};

MyClass myClass;

int main() {
    std::cout << "in main()" << std::endl;

    return 0;
}