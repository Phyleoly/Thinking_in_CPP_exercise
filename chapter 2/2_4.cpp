#include <iostream>
#include <string>
#include <fstream>

int main() 
{
    std::ifstream is("test.txt");
    std::string need_find;
    std::string word;
    int count = 0;

    std::cin >> need_find;
    while(is >> word) {
        if (word == need_find)
            count++;
    }

    std::cout<<count;
    
    return 0;
}