#include <iostream>

typedef struct {
    int i, j, k;
} ThreeDpoint;

int main()
{
    ThreeDpoint p[10];
    for(int i = 0; i < 10; i++) {
        p[i].i = i + 1;
        p[i].j = i + 2;
        p[i].k = i + 3;
    }

    std::cout << "sizeof(ThreeDpoint) = " << sizeof(ThreeDpoint) << std::endl;
    for(int i = 0; i < 10; i++) 
        std::cout << "&p[" << i << "] = " << (long)&p[i] << std::endl; 
}