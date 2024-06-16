#include <iostream>
#include <string>

int main()
{
    std::string str[10];
    for(int i = 0; i < 10; i++)
        str[i] = "aaa" + i;

    for(int i = 0; i < 10; i++)
        std::cout << str[i] << " ";

    return 0;
}