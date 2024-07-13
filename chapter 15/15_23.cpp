#include <iostream>
#include <string>
using namespace std;

class PetFood {
public:
    virtual string foodType() const = 0;
};

class Pet {
public:
    virtual string type() const = 0;
    virtual PetFood* eats() = 0;
    virtual PetFood& eatsRef() = 0; 
};

class Bird : public Pet {
public:
    string type() const { return "Bird"; }

    class BirdFood : public PetFood {
    public:
        string foodType() const {
            return "Bird food";
        }
    };

    PetFood* eats() { return &bf; }
    PetFood& eatsRef() { return bf; } 
private:
    BirdFood bf;
};

class Cat : public Pet {
public:
    string type() const { return "Cat"; }

    class CatFood : public PetFood {
    public:
        string foodType() const {
            return "Cat food";
        }
    };

    CatFood* eats() { return &cf; }
    CatFood& eatsRef() { return cf; } 
private:
    CatFood cf;
};

int main() {
    Bird b;
    Cat c;
    Pet* p[] = { &b, &c };
    for(int i = 0; i < sizeof p / sizeof *p; i++) {
        cout << p[i]->type() << " eats " 
             << p[i]->eats()->foodType() << endl;

        cout << p[i]->type() << " eats (ref) " 
             << p[i]->eatsRef().foodType() << endl;

        Cat::CatFood* cf = c.eats();
        Bird::BirdFood* bf;
        // bf = b.eats();
        bf = dynamic_cast<Bird::BirdFood*>(b.eats());
    }
}