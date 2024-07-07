#include <iostream>

class Class1 {
public:
    Class1() {
        std::cout << "Class1 constructor called" << std::endl;
    }
    Class1(const Class1&) {
        std::cout << "Class1 copy constructor called" << std::endl;
    }
};

class Class2 {
private:
    Class1 class1;
public:
    Class2() {
        std::cout << "Class2 constructor called" << std::endl;
    }
};

int main() {
    Class2 a;
    Class2 b = a;

    return 0;
}