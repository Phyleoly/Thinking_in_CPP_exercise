#include <iostream>

struct MyStruct
{
    void func();
};

void MyStruct::func() {
    std::cout << "in function" << std::endl;
}

int main()
{
    MyStruct obj;
    obj.func();

    return 0;
}
