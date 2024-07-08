#include <iostream>
#include <string>

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

    Bird(const Bird& other) : str(other.str), value(other.value) {
        std::cout << "copy constructor called" << std::endl;
    }

    int getValue() const { return value; }

    friend Bird operator+(const Bird& lhs, const Bird& rhs);
    friend Bird operator-(const Bird& lhs, const Bird& rhs);
    friend Bird operator*(const Bird& lhs, const Bird& rhs);
    friend Bird operator/(const Bird& lhs, const Bird& rhs);

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

Bird operator+(const Bird& lhs, const Bird& rhs) {
    Bird temp;
    temp.value = lhs.value + rhs.value;
    return temp;
}

Bird operator-(const Bird& lhs, const Bird& rhs) {
    Bird temp;
    temp.value = lhs.value - rhs.value;
    return temp;
}

Bird operator*(const Bird& lhs, const Bird& rhs) {
    Bird temp;
    temp.value = lhs.value * rhs.value;
    return temp;
}

Bird operator/(const Bird& lhs, const Bird& rhs) {
    Bird temp;
    if (rhs.value != 0) {
        temp.value = lhs.value / rhs.value;
    } else {
        std::cerr << "Division by zero error!" << std::endl;
        temp.value = 0; 
    }
    return temp;
}

int main() {
    Bird bird1(10);
    Bird bird2(5);
    Bird bird3;

    Bird resultAdd = bird1 + bird2;
    Bird resultSub = bird1 - bird2;
    Bird resultMul = bird1 * bird2;
    Bird resultDiv = bird1 / bird2;

    std::cout << "Bird1 + Bird2: " << resultAdd << std::endl;
    std::cout << "Bird1 - Bird2: " << resultSub << std::endl;
    std::cout << "Bird1 * Bird2: " << resultMul << std::endl;
    std::cout << "Bird1 / Bird2: " << resultDiv << std::endl;

    return 0;
}