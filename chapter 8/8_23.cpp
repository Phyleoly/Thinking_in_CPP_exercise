#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v) : value(v) {}

    void modifyValue() {
        value *= 2;
    }

    void printValue() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1(5);

    obj1.modifyValue();
    obj1.printValue();

    const MyClass obj2(10);

    obj2.printValue();

    // 尝试调用 const 对象的非 const 成员函数会导致编译错误
    // obj2.modifyValue();  

    return 0;
}
