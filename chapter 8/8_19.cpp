#include <iostream>

class MyClass {
private:
    const float constFloatMember;   
    float nonConstFloatMember;      

public:
    MyClass(float constFloat, float nonConstFloat)
        : constFloatMember(constFloat), nonConstFloatMember(nonConstFloat) {}

    void printMembers() const {
        std::cout << "Const float member: " << constFloatMember << std::endl;
        std::cout << "Non-const float member: " << nonConstFloatMember << std::endl;
    }
};

int main() {
    MyClass obj(3.14f, 2.718f);

    obj.printMembers();

    return 0;
}