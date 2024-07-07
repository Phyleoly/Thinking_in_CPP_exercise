#include <fstream>

extern std::ofstream out;

class Obj {
    char c;
public:
    Obj(char cc) : c(cc) {
        out << "Obj::Obj() for " << c << std::endl;
    }
    ~Obj() {
        out << "obj::~Obj() for " << c << std::endl;
    }
};

Obj a('a');

std::ofstream out("statdest.out");

void f() {
    static Obj b('b');
}

void g() {
    static Obj c('c');
}

int main() {
    out << "inside main()" << std::endl;
    f();
    out << "leaving main()" << std::endl;
}
