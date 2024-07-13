#include <iostream>
#include <ctime>

class Base {
public:
    virtual void virtualFunction() {}

    void nonVirtualFunction() {}
};

class Derived : public Base {
public:
    void virtualFunction() override {}

    void nonVirtualFunction() {}
};

int main() {
    const int iterations = 1000000; 
    Base* b = new Derived();

    clock_t virtualStartTime = clock();
    for (int i = 0; i < iterations; ++i) {
        b->virtualFunction();
    }
    clock_t virtualEndTime = clock();
    double virtualTime = double(virtualEndTime - virtualStartTime) / CLOCKS_PER_SEC;
    std::cout << "Time taken for virtualFunction(): " << virtualTime << " seconds" << std::endl;

    clock_t nonVirtualStartTime = clock();
    for (int i = 0; i < iterations; ++i) {
        b->nonVirtualFunction();
    }
    clock_t nonVirtualEndTime = clock();
    double nonVirtualTime = double(nonVirtualEndTime - nonVirtualStartTime) / CLOCKS_PER_SEC;
    std::cout << "Time taken for nonVirtualFunction(): " << nonVirtualTime << " seconds" << std::endl;

    delete b;
    return 0;
}