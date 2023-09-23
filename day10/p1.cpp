/* 每次读取一行字符串的输入
cin.getline();
cin.get();  
get()会更加仔细；
*/

#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
    const int MAX_size = 30;
    char s[MAX_size];
    cout<<"input your message: " << endl;
    cin.getline(s, MAX_size);  // 读取至换行符
    cout << s << endl;

    return 0;
}