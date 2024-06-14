#include "3_1.h"

int main() 
{
    myVoidFunction("void function");
    char resultChar = myCharFunction("char function");
    int resultInt = myIntFunction("int function");
    float resultFloat = myFloatFunction("float function");

    std::cout << "Returned char: " << resultChar << std::endl;
    std::cout << "Returned int: " << resultInt << std::endl;
    std::cout << "Returned float: " << resultFloat << std::endl;

    return 0;
}