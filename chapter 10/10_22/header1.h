// header1.h
#ifndef HEADER1_H
#define HEADER1_H

#include <iostream>

namespace Namespace1 {
    class MyClass {
    public:
        void func() {
            std::cout << "Namespace1::MyClass::func() called" << std::endl;
        }
    };
}

#endif // HEADER1_H