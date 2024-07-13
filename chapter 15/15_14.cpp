//: C15:AddingVirtuals.cpp
// Adding virtuals in derivation
#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string pname;
public:
    Pet(const string& petName) : pname(petName) {}
    virtual string name() const = 0; 
    virtual string speak() const = 0; 
};

class Dog : public Pet {
public:
    Dog(const string& petName) : Pet(petName) {}
    string name() const override { 
        return "Dog: " + pname;
    }
    string speak() const override { 
        return pname + " says 'Bark!'";
    }
    string sit() const {
        return pname + " sits"; 
    }
};

int main() {
    Pet* p[] = { new Dog("generic"), new Dog("bob") };
    cout << "p[0]->speak() = " << p[0]->speak() << endl;
    cout << "p[1]->speak() = " << p[1]->speak() << endl;
    //! cout << "p[1]->sit() = "
    //!     << p[1]->sit() << endl; // Illegal
}