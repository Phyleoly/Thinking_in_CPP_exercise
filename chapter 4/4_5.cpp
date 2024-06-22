#include <iostream>

struct MyStruct {
    int para;

    void f1(MyStruct *, int);
    void f2(MyStruct *);
};

void MyStruct::f1(MyStruct *ptr, int value) {
    ptr->para = value;
}

void MyStruct::f2(MyStruct *ptr) {
    std::cout << ptr->para << std::endl;
}

int main()
{
    MyStruct myStruct;

    myStruct.f1(&myStruct, 5);
    myStruct.f2(&myStruct);

    return 0;
}