#include <fstream>
using namespace std;
ofstream out("Order.out");

#define CLASS(ID) class ID { \
public: \
    ID(int) { out << #ID " constructor\n"; } \
    virtual ~ID() { out << #ID " destructor\n"; } \
    virtual void info() { out << #ID " info\n"; } \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1 {
    Member1 m1;
    Member2 m2;
public:
    Derived1(int) : m1(1), m2(2), Base1(3) {
        out << "Derived1 constructor\n";
    }
    ~Derived1() {
        out << "Derived1 destructor\n";
    }
    void info() override {
        out << "Derived1 info\n";
    }
};

class Derived2 : public Derived1 {
    Member3 m3;
    Member4 m4;
public:
    Derived2(int) : m3(1), Derived1(2), m4(3) {
        out << "Derived2 constructor\n";
    }
    ~Derived2() {
        out << "Derived2 destructor\n";
    }
    void info() override {
        out << "Derived2 info\n";
    }
};

int main() {
    Base1* b1 = new Derived1(1);
    Base1* b2 = new Derived2(2);

    b1->info();
    b2->info();

    delete b1;
    delete b2;
}