#include <iostream>
#include <ctime>

int main() {
    std::time_t currentTime = std::time(nullptr);

    const int dynamicConst = currentTime % 100;

    std::cout << "Current time: " << currentTime << std::endl;
    std::cout << "Dynamic const value: " << dynamicConst << std::endl;

    // 尝试修改 const 的值（编译时会报错）
    // dynamicConst = 42; // assignment of read-only variable ‘dynamicConst’ error

    return 0;
}
