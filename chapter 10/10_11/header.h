#ifndef HEADER_H
#define HEADER_H
#include <iostream>

class MyClass {
public:
    MyClass(int val) : _val(val) {}
    void setVal(int val) { _val = val; }
    void print() { std::cout << _val << std::endl; }
private:
    int _val;
};

#endif