#include <iostream>

class MyClass {
public:
    void modify() {
        std::cout << "Non-const member function called" << std::endl;
        data = 42;
    }

    void display() const {
        std::cout << "Const member function called" << std::endl;
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data = 0;
};

void byValue(MyClass obj) {
    obj.modify();
    obj.display();
}

void byReference(MyClass& obj) {
    obj.modify();
    obj.display();
}

void byConstReference(const MyClass& obj) {
    // obj.modify();
    obj.display();
}

int main() {
    MyClass obj;

    std::cout << "Calling byValue function:" << std::endl;
    byValue(obj);
    std::cout << "After byValue function call:" << std::endl;
    obj.display();

    std::cout << "\nCalling byReference function:" << std::endl;
    byReference(obj);
    std::cout << "After byReference function call:" << std::endl;
    obj.display();

    std::cout << "\nCalling byConstReference function:" << std::endl;
    byConstReference(obj);
    std::cout << "After byConstReference function call:" << std::endl;
    obj.display();

    return 0;
}
