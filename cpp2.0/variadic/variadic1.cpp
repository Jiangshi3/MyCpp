#include <iostream>
using namespace std;

void printX(){

}

//特化
template<typename T, typename... Type>
void printX(const T& firstArg, const Type&... args){
    cout << firstArg << endl;
    printX(args...);
}

//如果写了下面接收任意参数,下面这个跟上面可以共存,但此处的为 泛化版  永远不会被调用,前面特化把它取代了
template<typename T, typename... Type>
void printX(const Type&... args){
    printX(args...);
}

int main(int argc, const char* argv[])
{
    printX(1, "hello", 99);

    return 0;
}