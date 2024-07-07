#include <iostream>

int getNextValue(int param = 0);

static int* arrayPtr = nullptr;

int main() {
    int array[] = { 10, 20, 30, 40, -1 };

    arrayPtr = array;

    int value;
    do {
        value = getNextValue();
        if (value != -1) {
            std::cout << "Next value: " << value << std::endl;
        }
    } while (value != -1);

    return 0;
}

int getNextValue(int param) {
    if (param != 0) {
        arrayPtr = &param;
    }

    int currentValue = *arrayPtr;
    arrayPtr++;

    return currentValue;
}
