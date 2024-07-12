//: C14:Car.cpp
// Public composition

#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle(int speed, int fuel) {
        cout << "Vehicle constructed with speed: " << speed << " and fuel: " << fuel << endl;
    }

    void accelerate() const {
        cout << "Vehicle accelerating" << endl;
    }

    void brake() const {
        cout << "Vehicle braking" << endl;
    }

    void refuel(int amount) const {
        cout << "Refueling vehicle with " << amount << " units of fuel" << endl;
    }
};

class Engine {
public:
    void start() const {
        cout << "Engine starting" << endl;
    }
    void rev() const {
        cout << "Engine revving" << endl;
    }
    void stop() const {
        cout << "Engine stopping" << endl;
    }
};

class Wheel {
public:
    void inflate(int psi) const {
        cout << "Inflating wheel to " << psi << " psi" << endl;
    }
};

class Window {
public:
    void rollup() const {
        cout << "Rolling up window" << endl;
    }
    void rolldown() const {
        cout << "Rolling down window" << endl;
    }
};

class Door {
public:
    Window window;
    void open() const {
        cout << "Opening door" << endl;
    }
    void close() const {
        cout << "Closing door" << endl;
    }
};

class Car : public Vehicle {
public:
    Engine engine;
    Wheel wheel[4];
    Door left, right; // 2-door

    Car(int speed, int fuel) : Vehicle(speed, fuel) {
        cout << "Car constructed" << endl;
    }
};

int main() {
    Car car(100, 50);
    car.left.window.rollup();
    car.wheel[0].inflate(72);
    car.accelerate();
    car.brake();
    car.refuel(20);
    car.engine.start();
    car.engine.rev();
    car.engine.stop();
    return 0;
}