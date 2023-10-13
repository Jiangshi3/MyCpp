#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, const char* argv[])
{
    int i;
    int j{};  // j is initialized by 0
    int* p;
    int* q{};  // j is initialized by nullptr

    // int m{5.3};  // error:narrowing conversion
    int m(5.3);   // OK，m=5

    cout << max( {1, 3, 6} ) << endl;  // algorithm里面的max/min;  可以接收任意长度的参数； initializer_list<int>


    return 0;
}

