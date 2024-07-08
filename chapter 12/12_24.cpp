#include <iostream>
#include <string>

class FirstClass {
    std::string data;

public:
    FirstClass(const std::string& str) : data(str) {
        std::cout << "FirstClass constructor called with: " << data << std::endl;
    }

    void showData() const {
        std::cout << "Data in FirstClass: " << data << std::endl;
    }
};

class SecondClass {
    FirstClass firstObj;

public:
    SecondClass(const std::string& str) : firstObj(str) {
        std::cout << "SecondClass constructor called" << std::endl;
    }

    void accessFirstObject() const {
        firstObj.showData();
    }
};

int main() {
    SecondClass obj("Hello");

    obj.accessFirstObject();

    return 0;
}