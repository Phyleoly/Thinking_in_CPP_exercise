#include <string>
#include <iostream>
#include <cstring>

class StringStack {
    static const int size = 100;
    const std::string* stack[size];
    int index;
public:
    StringStack() : index(0) {
        memset(stack, 0, size * sizeof(std::string*));
    }
    void push(const std::string* s) {
        if(index < size)
            stack[index++] = s;
    }
    const std::string* pop() {
        if(index > 0) {
            const std::string* rv = stack[--index];
            stack[index] = 0;
            return rv;
        }
        return 0;
    }
};

std::string iceCream[] = {
    "pralines & cream",
    "fudge ripple",
    "jamocha almond fudge",
    "wild mountain blackberry",
    "raspberry sorbet",
    "lemon swirl",
    "rocky road",
    "deep chocolate fudge"
};

const int iCsz = 
    sizeof iceCream / sizeof *iceCream;

int main() {
    StringStack ss;
    for(int i = 0; i < iCsz; i++)
        ss.push(&iceCream[i]);
    const std::string* cp;
    while((cp = ss.pop()) != 0)
        std::cout << *cp << std::endl;
}