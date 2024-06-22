#include <iostream>
#include <string>

// 声明结构体Person
struct Person {
    std::string name;
    int age;

    void introduce() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

// 声明结构体Student，内嵌Person结构
struct Student {
    Person info; // 嵌套的Person结构作为Student的一部分
    int studentId;

    void displayInfo() {
        std::cout << "Student ID: " << studentId << std::endl;
        info.introduce(); // 调用内部的Person结构的成员函数
    }
};

int main() {
    // 创建一个Student对象并初始化
    Student student1;
    student1.info.name = "Alice";
    student1.info.age = 20;
    student1.studentId = 12345;

    // 调用Student的成员函数显示信息
    student1.displayInfo();

    return 0;
}