/*
cout.put(char);    //传入单个字符，输出单个字符
cout.write();
*/

#include <iostream>
using namespace std;
//函数原型
// put(char c)
// write(const char*c, int n)
int main() {
  char c;
  char a[50] = "this is a string...";
  cout << "use get() input char:";
  while ((c = cin.get())!='\n') {
    cout.put(c);
    cout.put('\n');
    cout.put('t').put('h').put('i').put('s').put('\n');  //输出：this
    cout.write(a, 12).put('\n');
    cout << "look"
         << "\t here!" << endl;
  }
  
}