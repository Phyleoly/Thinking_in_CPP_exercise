#include <iostream>

void printBinary(const unsigned char byte) {
    for(int i = 0; i < 8; i++) {
        if ((byte & (0x80 >> i)) == 0)
            std::cout<< 0;
        else  
            std::cout<< 1;
    }
    std::cout << " ";
}

int main()
{
    double real = 1.52163e4;

    //机器为小端法
    for(int nByte = sizeof(double) - 1; nByte >= 0 ; nByte--) {
        unsigned char *ptr;
        ptr = reinterpret_cast<unsigned char *>(&real) + nByte;
        printBinary(*ptr);
    }
    return 0;
}