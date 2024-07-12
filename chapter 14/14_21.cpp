//: C14:Instrument.cpp
// Inheritance & upcasting
#include <iostream>

enum note { middleC, Csharp, Cflat }; 

class Instrument {
public:
    void play(note) const {}
    void prepare() const { std::cout << "Instrument::prepare()" << std::endl; }
};

class Wind : public Instrument {};

void tune(Instrument& i) {
    i.play(middleC);
    i.prepare();
}

int main() {
    Wind flute;
    tune(flute); 
} ///:~