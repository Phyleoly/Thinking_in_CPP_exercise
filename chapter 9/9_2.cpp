#include <iostream>
using namespace std;

#define FLOOR(x, b) ((x)>=(b)?0:1)

int main() {
    int a = 5, b = 10;

    cout << "FLOOR(5, 10) = " << FLOOR(a, b) << endl;
    cout << "FLOOR(10, 5) = " << FLOOR(b, a) << endl;

    return 0;
}