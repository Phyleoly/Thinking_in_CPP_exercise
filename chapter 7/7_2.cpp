#include <iostream>
#include <string>

class Message {
private:
    std::string m_val;
public:
    Message(std::string val) : m_val(val) {}
    void print() { std::cout << m_val << std::endl; }
    void print(std::string val) { std::cout << val + m_val << std::endl; }
};

int main()
{
    Message message("message");
    message.print();
    message.print("string");

    return 0;
}