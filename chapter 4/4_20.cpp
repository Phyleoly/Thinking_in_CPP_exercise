#include <iostream>

// 空结构体，完全没有成员
struct EmptyStruct {};

// 只有数据成员的结构体
struct DataOnlyStruct {
    int data1;
    double data2;
};

// 既有数据成员又有函数成员的结构体
struct StructWithFunction {
    int data;
    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    std::cout << "Size of EmptyStruct: " << sizeof(EmptyStruct) << " bytes" << std::endl;
    std::cout << "Size of DataOnlyStruct: " << sizeof(DataOnlyStruct) << " bytes" << std::endl;
    std::cout << "Size of StructWithFunction: " << sizeof(StructWithFunction) << " bytes" << std::endl;

    return 0;
}