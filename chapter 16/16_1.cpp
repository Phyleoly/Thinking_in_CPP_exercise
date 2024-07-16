class Object {};

class Shape {};

class OShape : public Object, public Shape {};

class Circle : public Shape {};

class Square : public Shape {};

class Triangle : public Shape {};

class OCircle : public Circle, public OShape {};

class OSquare : public Square, public OShape {};

class OTriangle : public Triangle, public OShape {};

int main() {}