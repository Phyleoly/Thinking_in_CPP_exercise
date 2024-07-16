#include "Stack.h"
#include <iostream>

class Object {
public:
    virtual ~Object() {} 
};

class Shape : public Object {
public:
    virtual ~Shape() {} 
    virtual void draw() const = 0; 
};

class OShape : public Object, public Shape {
public:
    virtual ~OShape() {} 
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Circle drawing..." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Square drawing..." << std::endl;
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Triangle drawing..." << std::endl;
    }
};

class OCircle : public Circle, public OShape {
public:
    ~OCircle() {}
};

class OSquare : public Square, public OShape {
public:
    ~OSquare() {}
};

class OTriangle : public Triangle, public OShape {
public:
    ~OTriangle() {}
};

int main() {
    Stack<Shape> shapeStack;

    shapeStack.push(new Circle());
    shapeStack.push(new Square());
    shapeStack.push(new Triangle());

    for (auto it = shapeStack.begin(); it != shapeStack.end(); ++it) {
        Shape* shape = *it;
        if (shape) {
            shape->draw();
        }
    }

    return 0;
}