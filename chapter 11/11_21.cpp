#include <iostream>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor called with value: " << value << std::endl;
    }

    int getData() const {
        return data;
    }

private:
    int data;
    // MyClass(const MyClass&) {}
};
void processObject(MyClass obj) {
    std::cout << "Processing object with data: " << obj.getData() << std::endl;
}

int main() {

    MyClass myClass(1);
    processObject(myClass);
    return 0;
}