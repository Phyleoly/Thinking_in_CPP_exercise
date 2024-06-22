#include <iostream>
#include <string>

class Video {
private:
    int m_id;
    int m_rents; 
    std::string m_title;
    bool m_isRented;

public:
    Video(int id, int rents, std::string title);
    ~Video();
    void print();
};

Video::Video(int id, int rents, std::string title)
    : m_id(id), m_rents(rents), m_title(title), m_isRented(false) {}

Video::~Video() {}

void Video::print() {
    std::cout << "ID: " << m_id << ", Rents: " << m_rents
              << ", Title: " << m_title << std::endl;
    if (m_isRented)
        std::cout << "Status: Rented" << std::endl;
    else
        std::cout << "Status: Available" << std::endl;
}

int main() 
{
    // 创建一个 Video 对象并调用 print() 函数来测试
    Video myVideo(1, 10, "Inception");
    myVideo.print();

    return 0;
}