#include <iostream>

class bird {
public:
    void fly() {
        std::cout << "Flying!" << std::endl;
    }
};

class rock {
};

int main() {
    rock r; 
    void* voidPtr = &r; 

    bird* bPtr = static_cast<bird*>(voidPtr);

    bPtr->fly(); 

    return 0;
}
