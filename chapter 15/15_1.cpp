#include <iostream>

class Shape {
public:
    virtual void draw() { std::cout << "Shape::draw()" << std::endl; }
};

class Circle : public Shape {
public:
    void draw() { std::cout << "Circle::draw()" << std::endl; }
};

class Square : public Shape {
public:
    void draw() { std::cout << "Square::draw()" << std::endl; }
};

class Triangle : public Shape {
public:
    void draw() { std::cout << "Triangle::draw()" << std::endl; }
};

int main() {
    const int numShapes = 3;
    Shape* shapes[numShapes];

    shapes[0] = new Circle;
    shapes[1] = new Square;
    shapes[2] = new Triangle;

    for(int i = 0; i < numShapes; ++i) {
        shapes[i]->draw();
    }

    for(int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }

    return 0;
}