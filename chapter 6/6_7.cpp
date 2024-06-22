#include <iostream>

int main()
{
    double a[3] = {1, 2};
    std::cout << sizeof(a) << std::endl;

    double b[] = {1, 2, 3, 4};
    std::cout << sizeof(b) << std::endl;

    return 0;
}