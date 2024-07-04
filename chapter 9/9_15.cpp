#include <iostream>
#include <chrono>

// Time 类定义
class Time {
private:
    std::chrono::steady_clock::time_point start_time;

public:
    Time() {
        start_time = std::chrono::steady_clock::now();
    }

    ~Time() {
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds" << std::endl;
    }
};

class A {
public:
    A();

    inline A(int x) {
    }
};

A::A() {}

class B {
private:
    A objA;

public:
    B() : objA() {}

    inline B(int x) : objA(x) {}
};

int main() {
    const int size = 1000000; 

    {
        Time timer; 
        B arr[size];
    }

    {
        Time timer; 
        B arr[size] = {B(1), B(2), B(3), B(4), B(5)}; 
    }

    return 0;
}
