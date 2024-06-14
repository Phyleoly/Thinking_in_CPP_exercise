/*
 * @Author: Phyleoly Phyleoly@gmail.com
 * @Date: 2024-06-15 04:09:12
 * @LastEditTime: 2024-06-15 04:20:02
 * @Description: 
 * 
 * Copyright (c) 2024 by Phyeloly, All Rights Reserved. 
 */
#include <iostream>

void myVoidFunction(const char* format, ...);
char myCharFunction(const char* format, ...);
int myIntFunction(const char* format, ...);
float myFloatFunction(const char* format, ...);

void myVoidFunction(const char* format, ...) {
    std::cout << "myVoidFunction called with parameters: " << format << std::endl;
}

char myCharFunction(const char* format, ...) {
    std::cout << "myCharFunction called with parameters: " << format << std::endl;
    return 'a'; 
}

int myIntFunction(const char* format, ...) {
    std::cout << "myIntFunction called with parameters: " << format << std::endl;
    return 42; 
}

float myFloatFunction(const char* format, ...) {
    std::cout << "myFloatFunction called with parameters: " << format << std::endl;
    return 3.14f;
}