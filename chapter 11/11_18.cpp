#include <iostream>

class MyClass {
private:
    int data;

public:
    MyClass(int d = 0) : data(d) {
        std::cout << "Constructor called for data " << data << "\n";
    }

    MyClass(const MyClass& other) : data(other.data) {
        std::cout << "Copy constructor called for data " << data << "\n";
    }

    int getData() const {
        return data;
    }
};

int main() {
    std::cout << "Creating object obj1\n";
    MyClass obj1(10);

    std::cout << "\nCalling copy constructor with obj1\n";
    MyClass obj2 = obj1; 

    std::cout << "\nCreating object obj3 using default constructor\n";
    MyClass obj3; 

    std::cout << "\nCalling copy constructor with obj3\n";
    MyClass obj4 = obj3; 

    return 0;
}