#include <iostream>

class MyClass {
private:
    volatile int data;

public:
    MyClass(int initial) : data(initial) {}

    void modifyData() {
        data = data * 2;
    }

    void volatileModifyData() volatile {
        data = data + 1;
    }

    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

    void volatilePrintData() const volatile {
        std::cout << "Volatile Data: " << data << std::endl;
    }
};

int main() {
    MyClass obj1(5);

    obj1.modifyData();
    obj1.printData();

    volatile MyClass obj2(10);

    obj2.volatileModifyData();
    obj2.volatilePrintData();

    return 0;
}
