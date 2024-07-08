#include <iostream>
#include <sstream>
#include <fstream>

class MyClass {
private:
    char data;
public:
    MyClass(char dat) : data(dat) {}
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << obj.data;
        return os;
    } 

    friend std::istream& operator>>(std::istream& is, MyClass& obj) {
        is >> obj.data;
        return is;
    }
};

int main() {
    MyClass cw('A');
    std::cout << "Character: " << cw << std::endl;

    MyClass cw2('B');
    std::cout << "Enter a character: ";
    std::cin >> cw2;
    std::cout << "You entered: " << cw2 << std::endl;

    // Test with fstream
    std::ofstream outfile("char_output.txt");
    if (outfile.is_open()) {
        outfile << cw << std::endl;
        outfile.close();
    } else {
        std::cerr << "Unable to open file for writing!" << std::endl;
    }

    std::ifstream infile("char_output.txt");
    if (infile.is_open()) {
        MyClass cw3(' ');
        infile >> cw3;
        std::cout << "Read from file: " << cw3 << std::endl;
        infile.close();
    } else {
        std::cerr << "Unable to open file for reading!" << std::endl;
    }

    // Test with stringstream
    std::stringstream ss;
    ss << cw;
    std::string str = ss.str();
    std::cout << "String stream output: " << str << std::endl;

    return 0;
}