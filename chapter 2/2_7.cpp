#include <fstream>
#include <iostream>

int main()
{
    std::ifstream is("test.txt");
    std::string line;

    while (getline(is, line)) {
        std::cout << line << std::endl;
        std::cin.get();
    }
    
    return 0;
}