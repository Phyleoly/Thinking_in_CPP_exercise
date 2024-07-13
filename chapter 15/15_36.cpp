#include <iostream>
using namespace std;

class Dog {
public:
    int run(int i) const {
        cout << "run\n";
        return i;
    }
    int eat(int i) const {
        cout << "eat\n";
        return i;
    }
    int sleep(int i) const {
        cout << "ZZZ\n";
        return i;
    }

    typedef int (Dog::*PMF)(int) const;
};

class FunctionObject {
    Dog* ptr;
    Dog::PMF pmem;
public:
    FunctionObject(Dog* wp, Dog::PMF pmf)
        : ptr(wp), pmem(pmf) {
        cout << "FunctionObject constructor\n";
    }

    int operator()(int i) const {
        cout << "FunctionObject::operator()\n";
        return (ptr->*pmem)(i);
    }

    FunctionObject operator->*(Dog::PMF pmf) {
        cout << "operator->*\n";
        return FunctionObject(this->ptr, pmf);
    }
};

int main() {
    Dog w;
    Dog::PMF pmf = &Dog::run;
    // cout << (w->*pmf)(1) << endl;
    pmf = &Dog::sleep;
    // cout << (w->*pmf)(2) << endl;
    pmf = &Dog::eat;
    // cout << (w->*pmf)(3) << endl;
}