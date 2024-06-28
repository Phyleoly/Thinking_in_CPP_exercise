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
        // 尝试调用非 const 成员函数
        // modifyValue();  // 编译错误，const 成员函数不能调用非 const 成员函数
    }
};

int main() {
    const MyClass obj(5);

    obj.printValue();

    return 0;
}