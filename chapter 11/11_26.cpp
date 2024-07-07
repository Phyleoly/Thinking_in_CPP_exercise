#include <iostream>

class Simple2 {
public:
    int f(float) const { return 1; }  
    int f(int) const { return 2; }    
};

int main() {
    int (Simple2::*fp)(float) const;  
    fp = &Simple2::f;                 

    Simple2 obj;
    
    int result = (obj.*fp)(3.0f);  

    std::cout << "Result of f(float): " << result << std::endl;  

    fp = &Simple2::f;  

    result = (obj.*fp)(5);  

    std::cout << "Result of f(int): " << result << std::endl;  

    return 0;
}
