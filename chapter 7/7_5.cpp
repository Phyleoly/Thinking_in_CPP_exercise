#include <iostream>

class MyClass {
public:
    // 成员函数：使用默认参数
    void func(int a, int) {
        std::cout << "func called with parameters: " << a << std::endl;
    }
};

int main() {
    MyClass myClass;
    myClass.func(1, 2);

    return 0;
}