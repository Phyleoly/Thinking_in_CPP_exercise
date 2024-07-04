#include <iostream>
#include <fstream> 
#include <cstdlib> 

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <integer_between_5_and_10> <filename>" << std::endl;
        return 1; 
    }

    int number = std::atoi(argv[1]);

    if (number < 5 || number > 10) {
        std::cerr << "Error: Integer must be between 5 and 10." << std::endl;
        return 1; 
    }

    std::ifstream file(argv[2]);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file " << argv[2] << std::endl;
        return 1; 
    }

    std::cout << "Integer parameter: " << number << std::endl;
    std::cout << "File opened successfully: " << argv[2] << std::endl;


    file.close();

    return 0; 
}
