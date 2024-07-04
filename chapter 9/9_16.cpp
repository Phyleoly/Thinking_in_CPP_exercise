#include <iostream>

#define DEBUG(x) std::cout << #x " = " << x << std::endl

void removeOneCharacter(std::string str) {
    DEBUG(str);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }

    std::string str = argv[1];
    for (int i = str.length(); i > 0; --i) {
        removeOneCharacter(str.substr(0, i));
    }

    return 0;
}
