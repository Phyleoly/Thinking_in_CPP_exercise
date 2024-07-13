#include <iostream>
#include <vector>
using namespace std;

enum note { middleC, Csharp, Cflat }; 

class Instrument {
public:
    virtual ~Instrument() {}  

    void adjust(int) { /* ... */ }
};

class Wind : public Instrument {
public:
    void play(note) const {
        cout << "Wind::play()" << endl;
    }
    const char* what() const {
        return "Wind";
    }
};

class Percussion : public Instrument {
public:
    void play(note) const {
        cout << "Percussion::play()" << endl;
    }
    const char* what() const {
        return "Percussion";
    }
};

class Stringed : public Instrument {
public:
    void play(note) const {
        cout << "Stringed::play()" << endl;
    }
    const char* what() const {
        return "Stringed";
    }
};

class Brass : public Wind {
public:
    void play(note) const {
        cout << "Brass::play()" << endl;
    }
    const char* what() const {
        return "Brass";
    }
};

class Woodwind : public Wind {
public:
    void play(note) const {
        cout << "Woodwind::play()" << endl;
    }
    const char* what() const {
        return "Woodwind";
    }
};

void tune(Instrument& i) {
    if (auto p = dynamic_cast<Wind*>(&i)) {
        p->play(middleC);
    } else if (auto p = dynamic_cast<Percussion*>(&i)) {
        p->play(middleC);
    } else if (auto p = dynamic_cast<Stringed*>(&i)) {
        p->play(middleC);
    } else if (auto p = dynamic_cast<Brass*>(&i)) {
        p->play(middleC);
    } else if (auto p = dynamic_cast<Woodwind*>(&i)) {
        p->play(middleC);
    } else {
        cout << "Unknown Instrument type!" << endl;
    }
}

int main() {
    vector<Instrument*> orchestra = {
        new Wind,
        new Percussion,
        new Stringed,
        new Brass,
        new Woodwind
    };

    for (auto inst : orchestra) {
        tune(*inst);
    }

    for (auto inst : orchestra) {
        delete inst;
    }

    return 0;
}