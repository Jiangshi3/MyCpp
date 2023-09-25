//函数模板和特化
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T compareMax(T a, T b){return (a>b)?a:b;}

template<>
const char* compareMax(const char* s1, const char* s2){
    return (strcmp(s1, s2)>0)?s1:s2;
}

int main(int argc, const char* argv[])
{
    cout << compareMax(11, 22) << endl;
    cout << compareMax("hello", "world") << endl;
    // cout << sizeof("he llo") << endl;  // 输出：7； 原因：中间空格也占一位，字符串最后"\0"也占一位；

    return 0;
}

