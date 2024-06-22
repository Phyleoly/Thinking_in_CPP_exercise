#include <iostream>
#include <string>

class MyClass;

void displayPrivateData(const MyClass& obj);

class MyClass {
private:
    int privateData;

    friend void displayPrivateData(const MyClass& obj);

public:
    MyClass(int data) : privateData(data) {}

    int getPrivateData() const {
        return privateData;
    }
};

void displayPrivateData(const MyClass& obj) {
    std::cout << "Private data inside MyClass: " << obj.privateData << std::endl;
}


int main() 
{
    MyClass obj(42);

    std::cout << "Using member function: " << obj.getPrivateData() << std::endl;

    displayPrivateData(obj);

    return 0;
}