/*
 * @Author: Phyleoly Phyleoly@gmail.com
 * @Date: 2024-06-15 21:40:45
 * @LastEditTime: 2024-06-15 22:08:51
 * @Description: 
 * 
 * Copyright (c) 2024 by Phyeloly, All Rights Reserved. 
 */
#include <iostream>

unsigned char rol(unsigned char val) {
    int highbit;
    if (val & 0x80)
        highbit = 1;
    else
        highbit = 0;
    val <<= 1;
    val |= highbit;
    return val;
}

unsigned char ror(unsigned char val) {
    int lowbit;
    if (val & 1)
        lowbit = 1;
    else 
        lowbit = 0;
    val >>= 1;
    val |= (lowbit << 7);
    return val;
}

int main()
{
    unsigned int getval;
    unsigned char a, b;
    
    std::cout << "Enter a number between 0 and 255: ";
    std::cin >> getval; a = getval; 
     std::cout << "Enter a number between 0 and 255: ";
    std::cin >> getval; b = getval; 

    std::cout << "rol(: " << static_cast<unsigned int>(a) << "): " 
              << static_cast<unsigned int>(rol(a)) 
              << "  ror(" << static_cast<unsigned int>(a) << "): " 
              << static_cast<unsigned int>(ror(a)) << std::endl;
    std::cout << "rol(: " << static_cast<unsigned int>(b) 
              << "): " << static_cast<unsigned int>(rol(b)) 
              << "  ror(" << static_cast<unsigned int>(b) << "): " 
              << static_cast<unsigned int>(ror(b)) << std::endl;
    return 0;
}