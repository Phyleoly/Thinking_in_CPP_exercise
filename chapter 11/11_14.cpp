#include <iostream>

int recursiveFunction(int n) {
    if (n == 0) {
        return 0;
    } else {
        return recursiveFunction(n - 1);
    }
}

int main() {
    int result = recursiveFunction(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}