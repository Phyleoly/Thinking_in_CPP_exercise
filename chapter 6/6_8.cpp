#include <stack>
#include <string>
#include <iostream>

int main()
{
    std::string ss[5] = {"aaa", "bb", "qwe", "213", "x"};
    std::stack<std::string> st;

    for(int i = 0; i < 5; i++)
        st.push(ss[i]);

    for(int i = 0; i < 5; i++) {
        std::cout << st.top() << std::endl;
        st.pop();
    }

    return 0;
}