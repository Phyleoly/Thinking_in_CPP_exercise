#include <iostream>
#include <cstring>

char * f(const char *ptr) {
    char *tmp = new char[strlen(ptr) + 1];

    for(int i = 0; i < strlen(ptr); i++) 
        tmp[i] = ptr[i];

    tmp[strlen(ptr) + 1] = '\0';

    return tmp;
}

int main() 
{
    const char* originalArray = "Hello, world!";
    char* copiedArray = f(originalArray);

    std::cout << "Copied array: " << copiedArray << std::endl;

    delete[] copiedArray;

    return 0;
}