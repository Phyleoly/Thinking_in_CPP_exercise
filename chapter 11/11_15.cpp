#include <iostream>

class MyClass {
public:
    int x;
    double y;

    MyClass(int a, double b) : x(a), y(b) {
        std::cout << "Constructor called\n";
    }

    // 拷贝构造函数
    // 如果没有显式提供，则编译器会生成默认的
    // MyClass(const MyClass& other) {
    //     x = other.x;
    //     y = other.y;
    //     std::cout << "Copy constructor called\n";
    // }
};

int main() {
    MyClass obj1(10, 3.14);
    
    MyClass obj2 = obj1;

    std::cout << "obj2.x: " << obj2.x << ", obj2.y: " << obj2.y << std::endl;

    return 0;
}
