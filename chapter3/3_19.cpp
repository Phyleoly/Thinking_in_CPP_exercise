#include <iostream>

int main() 
{
    int a[10];
    char b[10];
    long c[10];
    float d[10];
    double e[10];

    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << "&a[" << i << "] = "
                  << reinterpret_cast<long>(&a[i]) << std::endl;

    std::cout << "\nsizeof(char) = " << sizeof(char) << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << "&b[" << i << "] = "
                  << reinterpret_cast<long>(&b[i]) << std::endl;

    std::cout << "\nsizeof(long) = " << sizeof(long) << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << "&c[" << i << "] = "
                  << reinterpret_cast<long>(&c[i]) << std::endl;

    std::cout << "\nsizeof(float) = " << sizeof(float) << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << "&d[" << i << "] = "
                  << reinterpret_cast<long>(&d[i]) << std::endl;

    std::cout << "\nsizeof(double) = " << sizeof(double) << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << "&e[" << i << "] = "
                  << reinterpret_cast<long>(&e[i]) << std::endl;

    return 0;
}