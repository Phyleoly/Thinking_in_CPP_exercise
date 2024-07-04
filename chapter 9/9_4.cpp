#include <iostream>
#include <ctime>

using namespace std;

inline void f1() {
    for (int i = 0; i < 1000000; ++i) {
        // 该函数功能待填充
    }
}

void f2() {
    for (int i = 0; i < 1000000; ++i) {
        // 该函数功能待填充
    }
}

int main() {
    clock_t start, end;
    double duration_f1, duration_f2;

    start = clock();
    for (int i = 0; i < 1000; ++i) {  
        f1();
    }
    end = clock();
    duration_f1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i < 1000; ++i) {
        f2();
    }
    end = clock();
    duration_f2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // 输出结果
    cout << "f1() 执行时间: " << duration_f1 << " 秒" << endl;
    cout << "f2() 执行时间: " << duration_f2 << " 秒" << endl;

    return 0;
}