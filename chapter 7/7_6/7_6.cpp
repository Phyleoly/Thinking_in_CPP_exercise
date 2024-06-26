#include <iostream>
#include "Stash3.h"

int main() {
    // 使用默认参数的构造函数初始化 Stash 对象
    Stash stash1(10);  // 使用默认的 quantity 和 next 值
    Stash stash2(20, 5);  // 初始化 size 和 quantity，使用默认的 next 值

    int data1 = 42;
    stash1.add(&data1);
    int* retrieved1 = static_cast<int*>(stash1.fetch(0));
    if (retrieved1)
        std::cout << "Retrieved data from stash1: " << *retrieved1 << std::endl;

    char data2[] = "Hello, world!";
    stash2.add(data2);
    char* retrieved2 = static_cast<char*>(stash2.fetch(0));
    if (retrieved2)
        std::cout << "Retrieved data from stash2: " << retrieved2 << std::endl;

    return 0;
}