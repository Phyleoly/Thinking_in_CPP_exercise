#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    std::ifstream inputFile("test.txt"); 

    std::string word;
    while (true) {
        inputFile >> word; 
        if (inputFile.eof()) {
            break; 
        }
        int mapping = 0; 
        if (word == "apple") {
            mapping = 1;
        } else if (word == "banana") {
            mapping = 2;
        } else if (word == "cherry") {
            mapping = 3;
        } else if (word == "exit") {
            mapping = 4; 
        }

        // 使用映射值进行 switch 操作
        switch (mapping) {
            case 1:
                std::cout << "You found an apple!" << std::endl;
                break;
            case 2:
                std::cout << "Banana is a yellow fruit." << std::endl;
                break;
            case 3:
                std::cout << "Cherries are red and delicious." << std::endl;
                break;
            case 4:
                std::cout << "Program will exit as requested." << std::endl;
                return 0; // 直接退出程序
            default:
                std::cout << "Unmapped word: " << word << std::endl;
                break;
        }
    }

    inputFile.close(); // 关闭文件

    return 0;
}