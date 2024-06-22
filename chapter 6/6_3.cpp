#include <iostream>

class Simple {
private:
    int m_para;
public:
    Simple(int para) : m_para(para) {
        std::cout << "An object of class Simple has been created" << std::endl;
        std::cout << m_para << std::endl;
    }

    ~Simple() {
        std::cout << "An object of class Simple has been destroyed" << std::endl;
        std::cout << m_para << std::endl;
    }
};

int main()
{
    Simple simple(5);

    return 0;
}