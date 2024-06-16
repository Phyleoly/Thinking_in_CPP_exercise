#include <iostream>
using namespace std;

#define DF(N) std::string N() { \
    return "function " #N " called..."; }

DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);

std::string (*func_tabble[])() = {a, b, c, d, e, f, g};

int main()
{
    while(1) {
        cout << "press a key from 'a' to 'g' "
            "or q to quit" << endl;
        char c, cr;
        cin.get(c); cin.get(cr);
        if (c == 'q')
            break;
        if (c < 'a' || c > 'g')
            continue;
        std::cout << (*func_tabble[c - 'a'])() << std::endl;
    }

    return 0;
}