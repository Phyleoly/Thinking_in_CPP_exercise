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

class BirdHouse {
private:
    Bird obj;
    Bird* ptr;
    Bird& ref;

public:
    BirdHouse(const Bird& bird1, const Bird& bird2, const Bird& bird3)
        : obj(bird1), ptr(new Bird(bird2)), ref(const_cast<Bird&>(bird3)) {}

    ~BirdHouse() {
        delete ptr;
    }

    BirdHouse(const BirdHouse& other)
        : obj(other.obj), ptr(new Bird(*other.ptr)), ref(const_cast<Bird&>(other.ref)) {}

    BirdHouse& operator=(const BirdHouse& other) {
        if (this != &other) {
            obj = other.obj;
            delete ptr;
            ptr = new Bird(*other.ptr);
            ref = const_cast<Bird&>(other.ref);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const BirdHouse& house) {
        os << "Object Bird: " << house.obj << std::endl;
        os << "Pointer Bird: " << *(house.ptr) << std::endl;
        os << "Reference Bird: " << house.ref;
        return os;
    }
};

int main() {
    Bird bird1;
    Bird bird2;
    Bird bird3;

    BirdHouse house1(bird1, bird2, bird3);
    std::cout << "House 1:" << std::endl << house1 << std::endl;

    Bird bird4;
    Bird bird5;
    Bird bird6;

    BirdHouse house2(bird4, bird5, bird6);
    std::cout << "House 2:" << std::endl << house2 << std::endl;

    house2 = house1;
    std::cout << "House 2 after assignment:" << std::endl << house2 << std::endl;

    return 0;
}