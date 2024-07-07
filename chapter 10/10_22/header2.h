// header2.h
#ifndef HEADER2_H
#define HEADER2_H

#include <iostream>

namespace Namespace2 {
    class MyClass {
    public:
        void func() {
            std::cout << "Namespace2::MyClass::func() called" << std::endl;
        }
    };
}

#endif // HEADER2_H