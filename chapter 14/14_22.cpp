//: C14:Instrument.cpp
// Inheritance & upcasting
#include <iostream>

enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
    virtual void play(note) const { std::cout << "Instrument::play(note)" << std::endl; }
};

class Wind : public Instrument {
public:
    void play(note) const { std::cout << "Wind::play(note)" << std::endl; }
};

void tune(Instrument& i) {
    // ...
    i.play(middleC);
}

int main() {
    Wind flute;
    tune(flute); // Upcasting
} ///:~