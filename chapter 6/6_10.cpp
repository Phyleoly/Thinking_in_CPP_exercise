#include <iostream>

class Simple {
private:
    int m_value;

public:
    // 没有显式定义构造函数

    void setValue(int value) {
        m_value = value;
    }

    void printValue() const {
        std::cout << "Value: " << m_value << std::endl;
    }
};

int main() {
    Simple obj1; // 使用默认构造函数创建对象

    obj1.setValue(5);
    obj1.printValue();

    // Simple obj2(10); // 使用带一个参数的构造函数创建对象

    // obj2.printValue();

    return 0;
}