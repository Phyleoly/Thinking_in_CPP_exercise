#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream is("test.txt");
    std::vector<std::string> lines;
    std::string line;

    while(getline(is, line)) {
        lines.push_back(line);
    }

    for(int i = lines.size() - 1; i >= 0; --i) 
        std::cout << i << ": " << lines[i] << std::endl;

    return 0;
}