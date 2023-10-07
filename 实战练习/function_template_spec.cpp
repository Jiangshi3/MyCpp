//函数模板和特化
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T compareMax(T a, T b){return (a>b)?a:b;}  //返回一个值（通过值传递），这意味着它会创建a和b的副本，并将比较结果的副本返回给调用者。这个版本适用于非修改性操作

// template <class T>
// T& compareMax(T a, T b){return (a>b)?a:b;}  //返回一个引用，这意味着它返回a或b的引用，取决于比较的结果。适用于需要修改原始值的情况，因为它可以直接修改传递给函数的参数
// 如果你只需要比较两个值并返回比较结果，第一种写法足够了

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

