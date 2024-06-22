#include <iostream>
#include <string>

// 定义 Lib 结构体
struct Lib {
    std::string a;
    std::string b;
    std::string c;
};

// 定义 Libc 类
class Libc {
private:
    std::string s[3];  // 私有数组成员

public:
    // 设置私有数组成员的值
    void seta(const std::string& value) { s[0] = value; }
    void setb(const std::string& value) { s[1] = value; }
    void setc(const std::string& value) { s[2] = value; }

    // 获取私有数组成员的值
    std::string geta() const { return s[0]; }
    std::string getb() const { return s[1]; }
    std::string getc() const { return s[2]; }
};

int main() {
    // 使用 Lib 结构体
    Lib x;
    x.a = "Value of a";
    x.b = "Value of b";
    x.c = "Value of c";

    std::cout << "Using struct Lib:" << std::endl;
    std::cout << "a: " << x.a << std::endl;
    std::cout << "b: " << x.b << std::endl;
    std::cout << "c: " << x.c << std::endl;

    std::cout << std::endl;

    // 使用 Libc 类
    Libc obj;
    obj.seta("Value of s[0]");
    obj.setb("Value of s[1]");
    obj.setc("Value of s[2]");

    std::cout << "Using class Libc:" << std::endl;
    std::cout << "s[0]: " << obj.geta() << std::endl;
    std::cout << "s[1]: " << obj.getb() << std::endl;
    std::cout << "s[2]: " << obj.getc() << std::endl;

    return 0;
}