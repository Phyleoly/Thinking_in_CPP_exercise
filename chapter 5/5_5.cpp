#include <iostream>

class ClassA {
private:
    int privateVal = 2;
    friend class ClassB;
    friend class ClassC;
};

class ClassB {
public:
    void print(ClassA& objA) {
        std::cout << "in ClassB print ClassA::privateVal = " << objA.privateVal << std::endl;
    }
};

class ClassC {
public:
    void print(ClassA& objA) {
        std::cout << "in ClassB print ClassC::privateVal = " << objA.privateVal << std::endl;
    }
};

int main()
{
    ClassA objA;
    ClassB objB;
    ClassC objC;

    objB.print(objA);
    objC.print(objA);

    return 0;
}