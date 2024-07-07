#include "header.h"

extern MyClass myClass;

int main() {
    myClass.print();
    myClass.setVal(4);
    myClass.print();

    return 0;
}