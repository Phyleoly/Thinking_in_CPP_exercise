#include <iostream>
#include <vector>

class Obj {
    static int i, j;
public:
    void f() const { std::cout << i++ << std::endl; }
    void g() const { std::cout << j++ << std::endl; }
};

int Obj::i = 47;
int Obj::j = 11;

class ObjContainer {
    std::vector<Obj*> a;
public:
    void add(Obj* obj) { a.push_back(obj); }
    friend class SmartPointer;
};

class SmartPointer {
    ObjContainer& oc;
    int index;
public:
    SmartPointer(ObjContainer& objc) : oc(objc), index(0) {}

    bool operator++() {
        if (index >= oc.a.size()) return false;
        if (oc.a[++index] == nullptr) return false;
        return true;
    }

    bool operator++(int) {
        return operator++();
    }

    bool operator--() {
        if (index <= 0) return false;
        if (oc.a[--index] == nullptr) return false;
        return true;
    }

    bool operator--(int) {
        return operator--();
    }

    // Overloaded operator->* to call member functions of Obj
    struct Callable {
        Obj* obj;
        void operator()(void (Obj::* func)() const) const {
            (obj->*func)();
        }
    };

    Callable operator->*(void (Obj::* func)() const) const {
        if (index >= oc.a.size() || index < 0 || oc.a[index] == nullptr) {
            std::cerr << "Invalid index or null pointer access\n";
            return Callable{nullptr};
        }
        return Callable{oc.a[index]};
    }
};

int main() {
    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;
    for (int i = 0; i < sz; i++)
        oc.add(&o[i]);
    SmartPointer sp(oc);

    std::cout << "Calling f() and g() using operator->*\n";
    do {
        sp->*&Obj::f;  // Using operator->* to call f()
        sp->*&Obj::g;  // Using operator->* to call g()
    } while (sp++);

    std::cout << "\nNow decrementing:\n";
    do {
        sp->*&Obj::f;  // Using operator->* to call f()
        sp->*&Obj::g;  // Using operator->* to call g()
    } while (sp--);

    return 0;
}
