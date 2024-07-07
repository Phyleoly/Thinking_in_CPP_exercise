#include <iostream>

int y;
int& r = y;
const int& q = 12;

int x = 0;
int main() {
    int& a = x;
    std::cout << "x = " << x << ", a = " << a << std::endl;
    a++;
    std::cout << "x = " << x << ", a = " << a << std::endl;
    return 0;
}