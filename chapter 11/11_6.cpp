#include <iostream>

void f(int**);

int main() {
    int i = 47;
    int* ip = &i;
    f(&ip);

    return 0;
}

void f(int** val) {
    std::cout << **val << std::endl;
}