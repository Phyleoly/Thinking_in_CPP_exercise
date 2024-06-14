#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream is("test.txt");
    std::string word;
    int count = 0;

    while(is >> word) {
        count++;
    }

    std::cout << count;

    return 0;
}