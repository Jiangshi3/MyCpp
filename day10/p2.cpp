#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  char stu[5][10];
  int i;
  for (i = 0; i < 5; i++)
    cin.getline(stu[i], 10, ',');  //分隔符字符，指定了何时停止读取输入。当达到指定的字符数（count-1）或者遇到分隔符字符时，读取操作会停止。
  for (i = 0; i < 5; i++)
    cout << stu[i] << endl;
  
  return 0;
}