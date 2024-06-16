#include <iostream>

void printBinary(const unsigned char val) {
    for(int i = 7; i >= 0; i--)
        if(val & (1 << i))
            std::cout << "1";
        else
            std::cout << "0";
}

int main()
{
    float f;
    unsigned char *str = (unsigned char *)&f;

    printBinary(str[0]);
    std::cout << std::endl;
    printBinary(str[1]);
    std::cout << std::endl;
    printBinary(str[2]);
    std::cout << std::endl;
    printBinary(str[3]);

    return 0;
}