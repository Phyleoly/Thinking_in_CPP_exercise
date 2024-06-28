#include <iostream>

void processFloat(float value) {
    const float& refValue = value; 

    std::cout << "Inside function: refValue = " << refValue << std::endl;
    // refValue = 20.0f; // 尝试修改refValue会导致编译错误
}

int main() {
    float num = 10.5f;
    
    processFloat(num);

    return 0;
}