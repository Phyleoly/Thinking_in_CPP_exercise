#include <iostream>
#include <vector>

using namespace std;

class Rodent {
public:
    virtual void eat() const {
        cout << "Rodent is eating" << endl;
    }

    virtual void sleep() const {
        cout << "Rodent is sleeping" << endl;
    }

    virtual void run() const {
        cout << "Rodent is running" << endl;
    }

    virtual ~Rodent() {}  
};

class Mouse : public Rodent {
public:
    void eat() const override {
        cout << "Mouse is eating cheese" << endl;
    }

    void sleep() const override {
        cout << "Mouse is sleeping in a nest" << endl;
    }

    void run() const override {
        cout << "Mouse is running fast" << endl;
    }
};

class Gerbil : public Rodent {
public:
    void eat() const override {
        cout << "Gerbil is eating seeds" << endl;
    }

    void sleep() const override {
        cout << "Gerbil is sleeping in a burrow" << endl;
    }

    void run() const override {
        cout << "Gerbil is running on a wheel" << endl;
    }
};

class Hamster : public Rodent {
public:
    void eat() const override {
        cout << "Hamster is eating fruits" << endl;
    }

    void sleep() const override {
        cout << "Hamster is sleeping in a cage" << endl;
    }

    void run() const override {
        cout << "Hamster is running in a ball" << endl;
    }
};

class BlueHamster : public Hamster {
public:
    void eat() const override {
        Hamster::eat();
        cout << "BlueHamster is eating fruits" << endl;
    }

    void sleep() const override {
        cout << "BlueHamster is sleeping in a cage" << endl;
    }

    void run() const override {
        cout << "BlueHamster is running in a ball" << endl;
    }
};

int main() {
    BlueHamster bh;
    bh.eat();
    return 0;
}