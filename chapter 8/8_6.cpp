#include <iostream>

int main() {
    // 创建一个 const 的 char 数组
    const char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    // 尝试修改数组中的某一个值（会导致编译错误）
    // charArray[2] = 'z'; 

    std::cout << "Contents of const char array:" << std::endl;
    for (int i = 0; i < sizeof(charArray) / sizeof(char); ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
