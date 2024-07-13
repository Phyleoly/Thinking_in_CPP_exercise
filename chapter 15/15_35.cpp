#include <iostream>
using namespace std;

class Shape {
public:
    enum Type { CircleType, SquareType, UnknownType };
    virtual ~Shape() {}
    virtual Type whatAmI() const { return UnknownType; }
};

class Circle : public Shape {
public:
    Type whatAmI() const override { return CircleType; }
};

class Square : public Shape {
public:
    Type whatAmI() const override { return SquareType; }
};

class Other {};

int main() {
    Circle c;
    Shape* s = &c; 
    s = static_cast<Shape*>(&c);
    Circle* cp = nullptr;
    Square* sp = nullptr;
    
    if (s->whatAmI() == Shape::CircleType) {
        cp = static_cast<Circle*>(s);
    } else if (s->whatAmI() == Shape::SquareType) {
        sp = static_cast<Square*>(s);
    }

    if (cp != nullptr)
        cout << "It's a circle!" << endl;
    if (sp != nullptr)
        cout << "It's a square!" << endl;

    // Other* op = static_cast<Other*>(s);  
    Other* op2 = (Other*)s; 

    return 0;
}
