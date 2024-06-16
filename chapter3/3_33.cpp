#include <iostream>

float retFloat(char para) {
    return 1.1f;
}

typedef float (*RetFloatPtr)(char);
RetFloatPtr retFuncPtr(int para) {
    // float (*fptr)(char);
    // fptr = retFloat;
    // return fptr;
    return retFloat;
}

int main()
{
     int input = 5; 
    char character = 'A'; 

    RetFloatPtr ptr = retFuncPtr(input);

    float result = ptr(character);

    std::cout << "Result: " << result << std::endl;
    return 0;
}