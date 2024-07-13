#include <iostream>
#include <chrono>

class X {
public:
    virtual void func() {}
};

class Y : public X {
public:
    void func() override {}
};

void testSimpleCall() {
    X obj;
    obj.func();
}

void testVirtualCall() {
    Y obj;
    obj.func();
}

int main() {
    auto start = std::chrono::steady_clock::now();
    testSimpleCall();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> simpleCallTime = end - start;

    start = std::chrono::steady_clock::now();
    testVirtualCall();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> virtualCallTime = end - start;

    std::cout << "Simple function call time: " << simpleCallTime.count() << " seconds\n";
    std::cout << "Virtual function call time: " << virtualCallTime.count() << " seconds\n";
    std::cout << "Difference: " << (virtualCallTime - simpleCallTime).count() << " seconds\n";

    return 0;
}