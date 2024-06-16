#include <iostream>
#define PR(x) \
    std::cout << (long)&x << std::endl
#define PRS(x, y, z) \
    PR(x); \
    PR(y); \
    PR(z)

char a, b, c;
int d, e ,f;
float g, h ,i;
double j, k, l;

int main()
{
    PRS(a, b, c);
    PRS(d, e, f);
    PRS(g, h, i);
    PRS(j, k, l);

    return 0;
}