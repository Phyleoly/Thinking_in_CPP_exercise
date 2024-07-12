//: C13:ArrayOperatorNew.cpp
// Operator new for arrays
#include <new> // Size_t definition
#include <iostream>
#include <fstream>
using namespace std;
ofstream trace("ArrayOperatorNew.out");

class Widget {
    enum { sz = 10 };
    int i[sz];

public:
    Widget() { trace << "*"; }
    ~Widget() { trace << "~"; }
    void* operator new(size_t sz) {
        trace << "Widget::new: "
              << sz << " bytes" << endl;
        return ::new char[sz];
    }
    void operator delete(void* p) {
        trace << "Widget::delete" << endl;
        ::delete [](char*)p;
    }
    void* operator new[](size_t sz) {
        trace << "Widget::new[]: "
              << sz << " bytes" << endl;
        return ::new char[sz];
    }
    void operator delete[](void* p) {
        trace << "Widget::delete[]" << endl;
        ::delete [](char*)p;
    }
};

class DerivedWidget : public Widget {
public:
    DerivedWidget() { trace << "+"; }
    ~DerivedWidget() { trace << "-"; }
};

int main() {
    trace << "new Widget" << endl;
    Widget* w = new Widget;
    trace << "\ndelete Widget" << endl;
    delete w;

    trace << "\nnew Widget[25]" << endl;
    Widget* wa = new Widget[25];
    trace << "\ndelete []Widget" << endl;
    delete []wa;

    trace << "\nnew DerivedWidget" << endl;
    DerivedWidget* dw = new DerivedWidget;
    trace << "\ndelete DerivedWidget" << endl;
    delete dw;

    trace << "\nnew DerivedWidget[25]" << endl;
    DerivedWidget* dwa = new DerivedWidget[25];
    trace << "\ndelete []DerivedWidget" << endl;
    delete []dwa;
}