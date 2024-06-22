#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor called" << endl;
    }

    ~MyClass() {
        cout << "Destructor called" << endl;
    }
};

int main() {

    for (int i = 0; i < 3; ++i) {
        MyClass obj;
        cout << "Inside loop iteration " << i << endl;
        if (i == 1) {
            goto end_loop;
        }
    }

    end_loop:
    cout << "Exited loop with goto" << endl;

    return 0;
}