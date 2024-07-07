#include <fstream>

std::ofstream out("statdest.out");

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

void f() {
    static Obj b('b');
}

void g() {
    static Obj c('c');
}

int main() {
    out << "inside main()" << std::endl;
    f();
    g();
    f();
    out << "leaving main()" << std::endl;
}
