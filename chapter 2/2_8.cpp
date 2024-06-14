#include <iostream>
#include <vector>

int main() 
{
    std::vector<float> f;

    for(int i = 0; i < 25; ++i)
        f.push_back((i + 1.01));

    for(int i = 0; i < 25; ++i)
        std::cout << f[i] << " ";

    return 0;
}