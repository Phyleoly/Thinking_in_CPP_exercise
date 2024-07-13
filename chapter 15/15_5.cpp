#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; 

class Instrument {
public:
    virtual void play(note) const {
        cout << "Instrument::play" << endl;
    }
    virtual void prepare() const {
        cout << "Instrument::prepare" << endl;
    }
};

class Wind : public Instrument {
public:
    void play(note) const {
        cout << "Wind::play" << endl;
    }
    void prepare() const {
        cout << "Wind::prepare" << endl;
    }
};

void tune(Instrument& i) {
    i.play(middleC);
    i.prepare();
}

int main() {
    Wind flute;
    tune(flute); 
} 