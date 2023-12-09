#include <iostream>
using namespace std;

// class T2;

class T2{
public:
    T2(){cout << "T2() constructor" << endl;}
    T2(int num):_content(num){cout << "T2(int num) constructor" << endl;}
    void print(){cout << "T2 content: " << _content << endl;}

private:
    int _content=2;
};

class T1{
public:
    T1(){cout << "T1() constructor" << endl;}
    T1(int num):_content(num){cout << "T1(int num) constructor" << endl;}
    // 这里T1写在T2的后面，知道类T2的完整定义；
    // 定义了一个类T1的转换操作符; 它允许将T1类型的对象转换为T2类型的对象
    operator T2(){
        return T2(_content);  // 这是实际的转换操作。在这里，它创建了一个T2类型的对象，使用了T2类的带参数的构造函数，参数是_content，也就是T1对象中的私有成员变量。
    }
    void print(){cout << "T1 content: " << _content << endl;}

private:
    int _content=1;
};

// T1::operator T2(){
//     return T2(_content);
// }



int main()
{
    T1 t1;
    T2 t2;
    t1.print();
    t2.print();
    t2 = t1;
    cout << "----" << endl;
    t1.print();
    t2.print();

    return 0;
}

/*
T1() constructor
T2() constructor
T1 content: 1
T2 content: 2
T2(int num) constructor
----
T1 content: 1
T2 content: 1
*/




