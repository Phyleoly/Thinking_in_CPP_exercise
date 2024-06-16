#include <iostream>
#include <string>

typedef struct {
    std::string str1;
    std::string str2;
    int num;
} MyStruct;

int main() 
{
    MyStruct instance = {"Hello", "World", 42};

    std::cout << "Initial values: " << instance.str1 << ", "
              << instance.str2 << ", " << instance.num << std::endl;

    MyStruct *ptr = &instance;

    ptr->str1 = "Updated";
    ptr->str2 = "Values";
    ptr->num = 100;

    std::cout << "Updated values via pointer: " << ptr->str1 << ", "
              << ptr->str2 << ", " << ptr->num << std::endl;

    return 0;
}