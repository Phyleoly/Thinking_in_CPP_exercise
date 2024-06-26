#include "Stack.h"
#include <iostream>
#include <string>

int main() {
    std::string arr[] = {"Hello", "World", "Stack", "Example"};

    void* void_arr[sizeof(arr) / sizeof(arr[0])];
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        void_arr[i] = new std::string(arr[i]);
    }

    Stack stack(void_arr, sizeof(arr) / sizeof(arr[0]));

    void* item;
    while ((item = stack.pop()) != nullptr) {
        std::cout << *static_cast<std::string*>(item) << std::endl;
        delete static_cast<std::string*>(item); 
    }

    return 0;
}