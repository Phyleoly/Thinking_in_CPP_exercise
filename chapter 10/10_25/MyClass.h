// MyClass.h
#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>
#include <iostream>

class MyClass {
private:
    std::string myString;

public:
    MyClass(const std::string& str) : myString(str) {}

    void print() {
        std::cout << "String member: " << myString << std::endl;
    }
};

#endif // MYCLASS_H