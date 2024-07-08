#include <string>
#include <iostream>

class Bird {
private:
    std::string str;
    static int count;
public:
    Bird() {
        ++count;
        str = "Bird#" + std::to_string(count);
    }

    Bird(const Bird& other) {
        std::cout << "copy constructor called" << std::endl;
        str = other.str;
    }

    friend std::ostream& operator<<(std::ostream& os, const Bird& obj) {
        os << obj.str;
        return os;
    }

    Bird operator=(const Bird& obj) const {
        std::cout << "=" << std::endl;
        return Bird();
    }
};

int Bird::count = 0;

int main() {
    Bird bird1;
    std::cout << bird1 << std::endl;

    Bird bird2 = bird1;
    std::cout << bird2 << std::endl;

    Bird bird3;
    bird3 = bird2;
    std::cout << bird2 << std::endl;

    return 0;
}