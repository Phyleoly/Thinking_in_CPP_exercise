#include <iostream>

#define USE_VARTYPE_ENUM // Define this to use vartype enum

class SuperVar {
#ifdef USE_VARTYPE_ENUM
public:
    enum Vartype {
        character,
        integer,
        floating_point
    };
#endif

private:
#ifdef USE_VARTYPE_ENUM
    Vartype vartype;
#else
    int vartype; // For compatibility without enum
#endif

    union {
        char c;
        int i;
        float f;
    };

public:
    SuperVar(char ch);
    SuperVar(int ii);
    SuperVar(float ff);
#ifdef USE_VARTYPE_ENUM
    void print(Vartype type);
#else
    void print(int type); // For compatibility without enum
#endif
};

#ifdef USE_VARTYPE_ENUM
SuperVar::SuperVar(char ch) {
    vartype = character;
    c = ch;
}

SuperVar::SuperVar(int ii) {
    vartype = integer;
    i = ii;
}

SuperVar::SuperVar(float ff) {
    vartype = floating_point;
    f = ff;
}

void SuperVar::print(Vartype type) {
    switch (type) {
    case character:
        std::cout << "character: " << c << std::endl;
        break;
    case integer:
        std::cout << "integer: " << i << std::endl;
        break;
    case floating_point:
        std::cout << "float: " << f << std::endl;
        break;
    }
}
#else
SuperVar::SuperVar(char ch) {
    vartype = 0; // character
    c = ch;
}

SuperVar::SuperVar(int ii) {
    vartype = 1; // integer
    i = ii;
}

SuperVar::SuperVar(float ff) {
    vartype = 2; // floating_point
    f = ff;
}

void SuperVar::print(int type) {
    switch (type) {
    case 0:
        std::cout << "character: " << c << std::endl;
        break;
    case 1:
        std::cout << "integer: " << i << std::endl;
        break;
    case 2:
        std::cout << "float: " << f << std::endl;
        break;
    }
}
#endif

int main() {
    SuperVar A('c'), B(12), C(1.44F);
#ifdef USE_VARTYPE_ENUM
    A.print(SuperVar::character);
    B.print(SuperVar::integer);
    C.print(SuperVar::floating_point);
#else
    A.print(0); // character
    B.print(1); // integer
    C.print(2); // floating_point
#endif
    return 0;
}