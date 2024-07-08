#include <string>
#include <iostream>

class Bird {
private:
    std::string str;
    int value; 
    static int count;

public:
    Bird() : value(0) {
        ++count;
        str = "Bird#" + std::to_string(count);
    }

    Bird(int v) : value(v) {
        ++count;
        str = "Bird#" + std::to_string(count);
    }

    Bird(const Bird& other) : value(other.value) {
        std::cout << "copy constructor called" << std::endl;
        str = other.str;
    }

    Bird operator+(const Bird& other) const {
        Bird temp;
        temp.value = this->value + other.value;
        return temp;
    }

    Bird operator-(const Bird& other) const {
        Bird temp;
        temp.value = this->value - other.value;
        return temp;
    }

    Bird operator*(const Bird& other) const {
        Bird temp;
        temp.value = this->value * other.value;
        return temp;
    }

    Bird operator/(const Bird& other) const {
        Bird temp;
        if (other.value != 0) {
            temp.value = this->value / other.value;
        } else {
            std::cerr << "Division by zero error!" << std::endl;
            temp.value = 0; 
        }
        return temp;
    }

    Bird& operator=(const Bird& obj) {
        std::cout << "=" << std::endl;
        if (this != &obj) {
            str = obj.str;
            value = obj.value;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Bird& obj) {
        os << obj.str << " Value: " << obj.value;
        return os;
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
    Bird bird1(10);
    Bird bird2(5);
    Bird bird3(2);

    Bird resultAdd = bird1 + bird2;
    Bird resultSub = bird1 - bird2;
    Bird resultMul = bird1 * bird2;
    Bird resultDiv = bird1 / bird2;

    std::cout << "Bird1 + Bird2: " << resultAdd << std::endl;
    std::cout << "Bird1 - Bird2: " << resultSub << std::endl;
    std::cout << "Bird1 * Bird2: " << resultMul << std::endl;
    std::cout << "Bird1 / Bird2: " << resultDiv << std::endl;

    BirdHouse house1(bird1, bird2, bird3);
    std::cout << "House 1:" << std::endl << house1 << std::endl;

    Bird bird4(8);
    Bird bird5(3);
    Bird bird6(1);

    BirdHouse house2(bird4, bird5, bird6);
    std::cout << "House 2:" << std::endl << house2 << std::endl;

    house2 = house1;
    std::cout << "House 2 after assignment:" << std::endl << house2 << std::endl;

    return 0;
}