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

    for(int i = 0; i < lines.size(); ++i)
        line += lines[i];

    std::cout << line;
    
    return 0;
}