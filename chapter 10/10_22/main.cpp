#include <iostream>
#include "header1.h"
#include "header2.h"

void testFunction() {
    using namespace Namespace1;
    using namespace Namespace2;

    Namespace1::MyClass obj1;
    obj1.func();

    Namespace2::MyClass obj2;
    obj2.func();

    Namespace1::MyClass obj3;
    Namespace2::MyClass obj4;

    obj3.func();
    obj4.func();
}

int main() {
    testFunction();

    return 0;
}