/*
动态分配new； 最后要delete
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char* argv[])
{
    char s1[] = "world";
    cout << s1 << endl;    // world
    cout << *s1 << endl;   // w
    cout << strlen(s1) << endl;    // 5
    cout << sizeof(s1) << endl;    // 6
    cout << sizeof(s1[0]) << endl; // 1

    const char* s2 = "hello";  //s2是一个指向const char类型的指针，所以就不能通过指针修改值： s2[0]='H'; 错误。
    char* ptr = new char[strlen(s2)+1];  // array new   
    strcpy(ptr, s2);
    cout << "s2=" << s2 << endl;    // hello
    cout << "*s2=" << *s2 << endl;  // h
    cout << ptr << endl;            // hello
    delete[] ptr;                        // array delete
    return 0;
}
