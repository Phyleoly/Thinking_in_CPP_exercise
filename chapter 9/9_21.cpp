#include <iostream>
#include <fstream>
#include <string>

#define IFOPEN(VAR, NAME) \
    std::ifstream VAR(NAME); \
    assure(VAR, NAME);

void assure(std::ifstream& stream, const std::string& filename) {
    if (!stream) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1); 
    }
}

int main() {
    std::string filename = "test.txt";
    
    IFOPEN(infile, filename)

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}
