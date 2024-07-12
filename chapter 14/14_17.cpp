class Base {};

class Derived1 : private Base {};

class Derived2 : protected Base {};

int main() {
    Derived1 d1;
    Derived2 d2;

    // d1 = (Base)d1;
    // d2 = (Base) d2;

    return 0;
}