#include <iostream>

struct MyStruct {
    int para;
};

void f1(MyStruct *ptr, int value) {
    ptr->para = value;
}

void f2(MyStruct *ptr) {
    std::cout << ptr->para << std::endl;
}

int main()
{
    MyStruct myStruct;

    f1(&myStruct, 5);
    f2(&myStruct);

    return 0;
}