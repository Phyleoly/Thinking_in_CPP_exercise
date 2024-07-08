#include <iostream>

class Orange; 

class Apple {
public:
    Apple() {}
    Apple(const Orange& orange) {
        std::cout << "Apple constructor with Orange object" << std::endl;
    }

    void callWithOrange(const Apple& apple) {
        Orange orange;
        apple.passOrange(orange);
    }

private:
    void passOrange(const Orange& orange) const {
        std::cout << "Received an Orange object" << std::endl;
    }
};

class Orange {
public:
    Orange() {
        std::cout << "Orange constructor" << std::endl;
    }
};

int main() {
    // Apple apple1 = Orange(); 

    Apple apple2 = static_cast<Apple>(Orange()); 

    Apple apple;
    apple.callWithOrange(apple2);

    return 0;
}
