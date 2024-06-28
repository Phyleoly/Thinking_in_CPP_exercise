#include <iostream>

void t(int*& ptr) {
    *ptr = 2;
}

void u(const int*& cip) {
    int i = *cip;
}

const char* v() {
    return "result of function v()";
}

const int* const w() {
    static int i;
    return &i;
}

int main() {
    int x = 0;
    int* ip = &x;
    const int* cip = &x;
    
    t(ip); 
    // t(cip);

    // u(ip); 
    u(cip);

    const char* ccp = v();

    const int* const ccip = w();
    const int* cip2 = w();

    // *w() = 1; 

    return 0;
}
