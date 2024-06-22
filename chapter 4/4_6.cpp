#include <iostream>

struct MyStruct
{
    int data;
    void setData(int data);
    int getData();
    void printData();
};

void MyStruct::setData(int data) {
    this->data = data;
}

int MyStruct::getData() {
    return this->data;
}

void MyStruct::printData() {
    std::cout << this->data << std::endl;
}

int main()
{
    struct MyStruct obj;
    obj.setData(10);
    obj.printData();

    return 0;
}
