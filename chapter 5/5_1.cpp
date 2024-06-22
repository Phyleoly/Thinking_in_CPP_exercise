#include <iostream>

class MyClass {
public:
    int publicVar;

    void publicFunc() {
        std::cout << "Public function called." << std::endl;
    }

private:
    int privateVar;

    void privateFunc() {
        std::cout << "Private function called." << std::endl;
    }

protected:
    int protectedVar;

    void protectedFunc() {
        std::cout << "Protected function called." << std::endl;
    }
};

int main() {
    MyClass obj;

    obj.publicVar = 1;
    obj.publicFunc();

    // 访问私有数据成员和函数成员（编译错误）
    // obj.privateVar = 2;  
    // obj.privateFunc();  

    // 访问受保护数据成员和函数成员（编译错误）
    // obj.protectedVar = 3;  
    // obj.protectedFunc();   

    return 0;
}