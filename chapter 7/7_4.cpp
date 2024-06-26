#include <iostream>

class MyClass {
public:
    // 成员函数：使用默认参数
    void func(int a = 0, int b = 0, int c = 0) {
        std::cout << "func called with parameters: " << a << ", " << b << ", " << c << std::endl;
    }
};

int main() {
    MyClass obj;

    obj.func(); 
    obj.func(10); 
    obj.func(20, 30); 
    obj.func(5, 15, 25); 

    return 0;
}