#include <stdio.h>

const int globalConst = 10;
const int globalExpression = globalConst * 5;

int main() {
    printf("Global const in: %d\n", globalConst);
    printf("Global expression in: %d\n", globalExpression);
    return 0;
}