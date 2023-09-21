#include <iostream>
#include <cstring>
//using namespace std;
// using std::strcmp;
using std::string;
using std::cout;
using std::endl;



template <class T> T Max(const T a, const T b)
 { 
    cout << "---template <class T> T Max()---" << endl;
    return (a > b) ? a : b; 
}
//特化
// template <> 返回类型 函数名<特化的数据类型>(参数表) {}
template<> const char* Max<const char*>(const char* a, const char* b){
    cout << "---const char* Max---"<<endl;
    return (strcmp(a, b)>=0)?a:b;    
}

template <> char* Max<char *>(char* a, char* b){
    cout << "---char* Max---"<<endl;
    return (strcmp(a, b)>=0)?a:b;
}

int main()
{
    char x1[] = "xy", x2[]="yz";
    cout << Max(2, 3) << endl;
    cout << Max(x1, x2) << endl;
    cout << Max("abc", "bcd") << endl;

    return 0;
}


// template <> 返回类型 函数名<特化的数据类型>(参数表) {}
template<typename T> T Min(T a, T b){return a<b?a:b;}
template<> const char* Min<const char*>(const char* a, const char* b){
    return (strcmp(a, b)<0)?a:b;
}
template<> char* Min<char* >(char* a, char* b){
    return (strcmp(a, b)<0)?a:b;
}

