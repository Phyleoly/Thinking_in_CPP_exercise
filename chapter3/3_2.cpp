#include <cmath>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for(int i = 2;  i <= n; ++i) {
        bool flag = true;
        for(int j = 2; j <= sqrt(i); ++j)
            if(i % j == 0) {
                flag = false;
                break;
            }
        if (flag)
            std::cout << i << " ";
    }

}