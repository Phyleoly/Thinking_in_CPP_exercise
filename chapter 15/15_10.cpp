#include <iostream>
using namespace std;

class Rodent {
public:
    virtual void eat() const = 0;
    virtual void sleep() const = 0;
    virtual void run() const = 0;
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

int main() {
    const int numRodents = 3;
    Rodent* rodents[numRodents] = { new Mouse, new Gerbil, new Hamster };

    for (int i = 0; i < numRodents; ++i) {
        rodents[i]->eat();
        rodents[i]->sleep();
        rodents[i]->run();
        cout << endl;
    }

    for (int i = 0; i < numRodents; ++i) {
        delete rodents[i];
    }

    return 0;
}