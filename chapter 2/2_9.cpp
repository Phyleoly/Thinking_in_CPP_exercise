#include <iostream>
#include <vector>

int main() 
{
    std::vector<float> f1;
    std::vector<float> f2;
    std::vector<float> f3;

    for(int i = 0; i < 25; ++i) {
        f1.push_back((i + 1.01));
        f2.push_back((i + 2.02));
        f3.push_back(f1[i] + f2[i]);
    }

    for(int i = 0; i < 25; ++i)
        std::cout << f1[i] << " ";
    std::cout << std::endl;

    for(int i = 0; i < 25; ++i)
        std::cout << f2[i] << " ";
    std::cout << std::endl;

    for(int i = 0; i < 25; ++i)
        std::cout << f3[i] << " ";
        
    return 0;
}