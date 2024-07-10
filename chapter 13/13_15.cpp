#include <new> // Size_t definition
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

ofstream trace("ArrayOperatorNew.out");

class Widget {
    enum { sz = 10 };
    int i[sz];
    static vector<Widget*> widgetPtrs;

public:
    Widget() { trace << "*"; }
    ~Widget() { trace << "~"; }

    void* operator new(size_t sz) {
        trace << "Widget::new: " << sz << " bytes" << endl;
        Widget* p = static_cast<Widget*>(::operator new(sz));
        widgetPtrs.push_back(p);
        return p;
    }

    void operator delete(void* p) {
        trace << "Widget::delete" << endl;
        for(auto it = widgetPtrs.begin(); it!= widgetPtrs.end(); it++) {
            if(*it == p) {
                widgetPtrs.erase(it);
            }
        }
        ::operator delete(p);
    }

    void* operator new[](size_t sz) {
        trace << "Widget::new[]: " << sz << " bytes" << endl;
        Widget* p = static_cast<Widget*>(::operator new[](sz));
        widgetPtrs.push_back(p);
        return p;
    }

    void operator delete[](void* p) {
        trace << "Widget::delete[]" << endl;
        for(auto it = widgetPtrs.begin(); it!= widgetPtrs.end(); it++) {
            if(*it == p) {
                widgetPtrs.erase(it);
            }
        }
        ::operator delete[](p);
    }

    static size_t getWidgetCount() {
        return widgetPtrs.size();
    }

};

vector<Widget*> Widget::widgetPtrs;

class MemoryChecker {
public:
    ~MemoryChecker() {
        cout << "Number of Widgets still allocated: " << Widget::getWidgetCount() << endl;
    }
};

int main() {
    MemoryChecker mc;
    
    trace << "new Widget" << endl;
    Widget* w = new Widget;
    trace << "\ndelete Widget" << endl;
    delete w;

    trace << "\nnew Widget[25]" << endl;
    Widget* wa = new Widget[25];
    trace << "\ndelete []Widget" << endl;
    delete []wa;

    trace << "\nnew Widget" << endl;
    w = new Widget;
    trace << "\nnew Widget" << endl;
    Widget* w2 = new Widget;
    trace << "\ndelete Widget" << endl;
    delete w;
    
    return 0;
}