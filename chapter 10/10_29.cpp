#include <iostream>
#include <string>

class PrintString {
private:
    std::string val;
public:
    PrintString(std::string para) : val(para) {}
    void print() const {
        std::cout << val << std::endl;
    }
};

class MyClass {
private:
    static PrintString PrintStringArr[];
    static int arrSize; 
    static const PrintString PrintStringArr1[];
    static int arr1Size;
public:
    static void print() {
        for(int i = 0; i < arrSize; i++) 
            PrintStringArr[i].print();
        for(int i = 0; i < arr1Size; i++)
            PrintStringArr1[i].print();
    }
};

PrintString MyClass::PrintStringArr[] = {PrintString("a"), PrintString("bcd")};
int MyClass::arrSize = sizeof MyClass::PrintStringArr / sizeof(PrintString);

const PrintString MyClass::PrintStringArr1[] = {PrintString("string"), PrintString("int"), PrintString("double")};
int MyClass::arr1Size = sizeof MyClass::PrintStringArr1 / sizeof(PrintString);

int main() {
    MyClass::print();

    return 0;
}