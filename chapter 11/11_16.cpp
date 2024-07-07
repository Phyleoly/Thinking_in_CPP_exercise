#include <iostream>

class MyClass {
public:
    int data;

    MyClass(int d) : data(d) {
        std::cout << "Constructor called for data " << data << "\n";
    }

    MyClass(const MyClass& other) : data(other.data) {
        std::cout << "Copy constructor called for data " << data << "\n";
    }
};

void passByValue(MyClass obj) {
    std::cout << "Inside passByValue function\n";
}

MyClass returnByValue(int d) {
    MyClass newObj(d);
    return newObj;
}

int main() {
    std::cout << "Creating object obj1\n";
    MyClass obj1(10);

    std::cout << "\nCalling passByValue function\n";
    passByValue(obj1);

    std::cout << "\nCalling returnByValue function\n";
    MyClass obj2 = returnByValue(20);

    return 0;
}