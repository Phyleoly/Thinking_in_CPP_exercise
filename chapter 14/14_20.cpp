#include <iostream>

class SpaceShip {
public:
    SpaceShip() {}
    ~SpaceShip() {}
    void fly() { std::cout << "I can fly" << std::endl; }
};

class Shuttle : public SpaceShip {
public:
    Shuttle() {}
    ~Shuttle() {}
    void land() { std::cout << "landed" << std::endl; }
};

int main() {
    Shuttle shuttle;
    SpaceShip* spaceShip = (SpaceShip*)&shuttle;

    // spaceShip->land();

    return 0;
}