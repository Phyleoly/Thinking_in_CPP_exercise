#include <iostream>

int main() 
{
    char c;
    while (true) {
        std::cout << "MAIN MENU:" << std::endl;
        std::cout << "l: left, r: right, q: quit ->";
        std::cin >> c;
        switch (c) {
            case 'q' : 
                break;
            case 'l' : {
                std::cout << "LEFT MENU:" << std::endl;
                std::cout << "select a or b: ";
                std::cin >> c;
                switch (c) {
                    case 'a' : {
                        std::cout << "you chose 'a'" << std::endl;
                        continue;
                    } 
                    case 'b' : {
                        std::cout << "you chose 'b'" << std::endl;
                        continue;
                    }
                    default : {
                        std::cout << "you didn't choose a or b" << std::endl;
                        continue;
                    }
                }
            }
            case 'r' : {
                std::cout << "RIGHT MENU:" << std::endl;
                std::cout << "select c or d: ";
                std::cin >> c;
                switch (c) {
                    case 'c' : {
                        std::cout << "you chose 'c'" << std::endl;
                        continue;
                    }
                    case 'd' : {
                        std::cout << "you chose 'd'" << std::endl;
                        continue;
                    }
                    default : {
                        std::cout << "you didn't choose c or d!" << std::endl;
                        continue;
                    }
                }
            default :
                std::cout << "you must type l or r or q!" << std::endl;
            }
        }
        break;
    }
    std::cout << "quitting menu..." << std::endl;
    return 0;
}