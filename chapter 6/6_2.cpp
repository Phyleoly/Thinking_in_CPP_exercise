#include <iostream>

class Simple {
public:
    Simple() {
        std::cout << "An object of class Simple has been created" << std::endl;
    }

    ~Simple() {
        std::cout << "An object of class Simple has been destroyed" << std::endl;
    }
};

int main()
{
    Simple simple;

    return 0;
}