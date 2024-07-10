#include <cstdlib>
#include <new>
#include <iostream>

int count = 0;

void out_of_memory() {
    std::cerr << "memory exhausted after " << count
        << " allocations!" << std::endl;
    exit(1);
}

int main() {
    std::set_new_handler(out_of_memory);
    while(1) {
        count++;
        new int[1000];
    }
}