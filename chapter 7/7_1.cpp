#include <iostream>
#include <fstream>
#include <string>

class Text {
public:
    Text() {}
    Text(std::string filename) {
        std::ifstream is(filename);
        if(is.is_open()) {
            std::string line;
            while(getline(is, line)) 
                m_fileContents += line + '\n';
            is.close();
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
    ~Text() {}
    std::string contents() { return m_fileContents; }

private:
    std::string m_fileContents;
};

int main()
{
    Text text("test");

    std::cout << text.contents() << std::endl;

    return 0;
}