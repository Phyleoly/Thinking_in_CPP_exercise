#include <iostream>

int main()
{
    const double conArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    volatile double conArrv[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    for(int i = 0; i < 5; i++) {
        double& ref = const_cast<double&>(conArr[i]);
        ref = i + 1.7;
        double& refv = const_cast<double&>(conArrv[i]);
        refv = i + 1.8;
    }

    for(int i =0; i < 5; i++)
        std::cout << conArr[i] << " ";

    std::cout << std::endl;

    for(int i =0; i < 5; i++)
        std::cout << conArrv[i] << " ";

    return 0;
}