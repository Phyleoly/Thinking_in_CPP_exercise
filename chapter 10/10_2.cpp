#include <iostream>

int getFibonacci(bool val = false) {
    static int last, now;
    if(val) {
        last = 0;
        now = 1;
    } else {
        int tmp = last + now;
        last = now;
        now = tmp;
    }
    return now;
}

int main() {
    std::cout << getFibonacci(true) << " ";
    for(int i = 1; i <= 10; i++)
        std::cout << getFibonacci() << " ";
    return 0;
}