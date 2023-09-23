/* page: 95
使用new创建动态struct；在运行时才创建；
*/

#include <iostream>
using namespace std;

//结构体一般声明在外部
struct inflatable{
    char name[20];
    float volume;
    double price;
};

int main(int argc, const char* argv[])
{
    inflatable* p = new inflatable;  //  !!!!  typename* pointname = new typename;
    cout << "Enter your inflatable name: " << endl;
    cin.get(p->name, 20);
    cout << "Enter your volume: " << endl;
    cin >> p->volume;
    cout << "Enter your price: " << endl;
    cin >> (*p).price;

    cout<<"Name: " << p->name << endl;
    cout <<"volume: " << (*p).volume << endl;  //等同于 p->volume;   因为(*p)就是被指向的值，也就是结构本身，所以结构本身可以用成员运算符句点
    cout << "Price: " << p->price << endl;
    
    delete p;   // 切结有new，一定要记得delete ！！！！

    return 0;
}

/* 拷贝
char* p = new char[strlen(temp)+1];
strcpy(p, temp);
*/
