#include <iostream>

class A {
public:
    A() {
        std::cout << "A default constructor called." << std::endl;
    }
};

class B {
private:
    A objA; 

public:
    B() {
        std::cout << "B constructor called." << std::endl;
    }
};

int main() {
    const int size = 5;
    B arr[size]; 

    return 0;
}
