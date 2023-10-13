/*nullptr*/
#include <iostream>
using namespace std;

void f(int x){
    cout << "--int x--" << endl;
}

void f(void *){
    cout << "--void *--" << endl;
}

int main(int argc, const char* argv[])
{
    int i=0;
    f(i);
    //  c语言中将NULL定义为空指针，而在c++中直接定义为0，这是因为C++是强类型的，void *是不能隐式转换成其他指针类型的。
    if(NULL==0) cout << "NULL=0" << endl;
    
    f(nullptr);
    // nullptr_t为nullptr的类型
    //typedef decltype(nullptr) nullptr_t;
    nullptr_t ptr1; 
    f(ptr1);

    return 0;
}