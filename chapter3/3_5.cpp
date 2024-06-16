#include <iostream>

int main()
{
    int x = 1, y = 2, z = 3;
    int a1 = x + y - 2 / 2 + z;         //5
    int a2 = x + (y - 2) / (2 + z);     //1

    std::cout << "a1 = " << a1 << " a2 = " << a2;
    
    return 0;
}