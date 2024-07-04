#include <iostream>
#include <ctime>

using namespace std;

inline void inlineFunction1() {
    for (int i = 0; i < 1000000; ++i) {
        int x = i * 2 + 1;
    }
}

void nonInlineFunction1() {
    for (int i = 0; i < 1000000; ++i) {
        int x = i * 2 + 1;
    }
}

inline void inlineFunction2() {
    long long sum = 0;
    for (int i = 1; i <= 10000; ++i) {
        sum += i * i;
    }
}

void nonInlineFunction2() {
    long long sum = 0;
    for (int i = 1; i <= 10000; ++i) {
        sum += i * i;
    }
}

int main() {
    clock_t start, end;
    double duration_inline1, duration_nonInline1, duration_inline2, duration_nonInline2;

    start = clock();
    for (int i = 0; i < 1000; ++i) {
        inlineFunction1();
    }
    end = clock();
    duration_inline1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i < 1000; ++i) {
        nonInlineFunction1();
    }
    end = clock();
    duration_nonInline1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i < 1000; ++i) {
        inlineFunction2();
    }
    end = clock();
    duration_inline2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i < 1000; ++i) {
        nonInlineFunction2();
    }
    end = clock();
    duration_nonInline2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // 输出结果
    cout << "内联函数1 执行时间: " << duration_inline1 << " 秒" << endl;
    cout << "非内联函数1 执行时间: " << duration_nonInline1 << " 秒" << endl;
    cout << "内联函数2 执行时间: " << duration_inline2 << " 秒" << endl;
    cout << "非内联函数2 执行时间: " << duration_nonInline2 << " 秒" << endl;

    return 0;
}
