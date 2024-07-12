#include <iostream>

class MyClass {
private:
    long myLong;

public:
    MyClass(long value) : myLong(value) {}

    void display() const {
        std::cout << "Value of myLong: " << myLong << std::endl;
    }
};

int main() {
    MyClass obj(123456789L);
    obj.display();

    return 0;
}