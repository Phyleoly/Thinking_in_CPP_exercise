#include <iostream>

template<typename T>
T fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    T a = 0;
    T b = 1;
    T result = b;
    
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main() {
    std::cout << "Fibonacci(10) (int): " << fibonacci<int>(10) << std::endl;
    std::cout << "Fibonacci(10) (long): " << fibonacci<long>(10) << std::endl;
    std::cout << "Fibonacci(10) (float): " << fibonacci<float>(10) << std::endl;
    std::cout << "Fibonacci(10) (double): " << fibonacci<double>(10) << std::endl;

    return 0;
}