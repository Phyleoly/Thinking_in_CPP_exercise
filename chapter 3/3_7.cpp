/*
 * @Author: Phyleoly Phyleoly@gmail.com
 * @Date: 2024-06-15 13:28:41
 * @LastEditTime: 2024-06-15 13:33:19
 * @Description: 
 * 
 * Copyright (c) 2024 by Phyeloly, All Rights Reserved. 
 */
#include <iostream>
#include <string>

void f1(std::string *ptr) {
    *ptr = "f1";
}

void f2(std::string& ptr) {
    ptr = "f2";
}

int main()
{
    std::string str("main");

    f1(&str);
    std::cout << str << std::endl;

    f2(str);
    std::cout << str << std::endl;

    return 0;
}