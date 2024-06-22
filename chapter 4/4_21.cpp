#include <iostream>

// 定义一个结构体
struct MyStruct {
    int x;
    double y;
};

// 定义一个枚举类型
enum class MyEnum {
    Value1,
    Value2,
    Value3
};

// 定义一个联合类型
union MyUnion {
    int a;
    float b;
};

int main() {
    // 使用 typedef 创建类型别名
    typedef MyStruct StructAlias;
    typedef MyEnum EnumAlias;
    typedef MyUnion UnionAlias;

    // 使用 using 创建类型别名（C++11及以后的写法）
    using StructAlias2 = MyStruct;
    using EnumAlias2 = MyEnum;
    using UnionAlias2 = MyUnion;

    // 测试类型别名的等价性
    StructAlias s1;
    StructAlias2 s2;
    s1.x = 10;
    s1.y = 3.14;
    s2.x = 20;
    s2.y = 6.28;

    EnumAlias e1 = EnumAlias::Value1;
    EnumAlias2 e2 = EnumAlias2::Value2;

    UnionAlias u1;
    UnionAlias2 u2;
    u1.a = 100;
    u2.b = 3.5;

    // 输出测试结果
    std::cout << "s1.x = " << s1.x << ", s1.y = " << s1.y << std::endl;
    std::cout << "s2.x = " << s2.x << ", s2.y = " << s2.y << std::endl;

    std::cout << "e1 = " << static_cast<int>(e1) << std::endl;
    std::cout << "e2 = " << static_cast<int>(e2) << std::endl;

    std::cout << "u1.a = " << u1.a << ", u2.b = " << u2.b << std::endl;

    return 0;
}