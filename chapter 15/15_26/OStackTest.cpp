//: C15:OStackTest.cpp
//{T} OStackTest.cpp
#include "OStack.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class MyClass : public Object {
    string name;
    int value;
public:
    MyClass(const string& n, int v) : name(n), value(v) {}
    ~MyClass() {
        cout << "deleting MyClass: " << name << " with value " << value << endl;
    }
    friend ostream& operator<<(ostream& os, const MyClass& mc) {
        return os << "MyClass name: " << mc.name << ", value: " << mc.value;
    }
};

int main(int argc, char* argv[]) {
    ifstream in(argv[1]);
    Stack textlines;
    string line;
    int value = 0;
    while(getline(in, line)) {
        textlines.push(new MyClass(line, value++));
    }
    MyClass* mc;
    for(int i = 0; i < 10; i++) {
        if((mc = (MyClass*)textlines.pop()) == 0) break;
        cout << *mc << endl;
        delete mc;
    }
    cout << "Letting the destructor do the rest:" << endl;
    return 0;
}