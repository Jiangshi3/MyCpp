/*
总结1： 一个类定义了虚函数，那么在编译阶段，编译器给这个类产生一个vtbl虚函数表，
        虚函数表主要存储RTTI和虚函数的地址；  **RTTI**（run-time type information）运行时类型信息；
总结2： 一个类里面定义了虚函数，那么这个类定义的对象，运行时，内存中多存储一个vptr虚函数指针；
        一个类型定义多个对象，他们的vptr指向的都是同一张虚函数表vtbl；
总结3： 一个类里面虚函数的个数，不影响对象内存大小，影响的是虚函数表的大小；
*/

/*
虚函数指针（Virtual Function Pointer）： 在具有虚函数的类的对象中，通常会有一个额外的指针，该指针指向该类的虚函数表（也称为虚表）。
这个指针通常称为虚函数指针（vptr）。每个对象都有一个虚函数指针，这个指针在对象创建时初始化，并指向相应类的虚函数表。虚函数指针的存在使得在运行时可以动态地确定要调用的虚函数。

虚函数表（Virtual Function Table）： 虚函数表是一个数组，包含了该类的虚函数的地址。每个具有虚函数的类都有自己的虚函数表。
虚函数表在编译阶段创建，并在运行时被使用。当调用虚函数时，实际上是通过虚函数指针找到对象的虚函数表，然后在虚函数表中查找要调用的虚函数的地址。
*/


#include <iostream>
#include <typeinfo>
using namespace std;

class Base{
public:
    Base(int x=99):data_base(x){}
    virtual void show(){cout << "Base::show()" << endl;};
    void show(int x) {cout << "Base::show(int)" << endl;}

protected:
    int data_base;
};

class Derive:public Base{
public:
    Derive(int x=100):Base(x), data_de(x){}
    virtual void show() override{cout << "Derive::show()" << endl;}

private:
    int data_de;
};


int main(){
    Derive d(50);
    Base* ptr = &d;

    /*
        （虚函数的地址）动态（运行时）绑定（函数的调用）
    */
    ptr->show();     // Derive::show()
    ptr->show(20);   // Base::show(int)

    //sizeof大小要加上了vptr； 32位操作系统一个指针大小为4个字节
    cout << sizeof(Base) << endl;     //  8
    cout << sizeof(Derive) << endl;   //  12

    cout << typeid(ptr).name() << endl;  // class Base*
    /*
        如果Base没有虚函数，*ptr识别的就是编译时期的类型；
        如果Base有虚函数，*ptr识别的就是运行时期的类型 RTTI类型；
    */
    cout << typeid(*ptr).name() << endl; //

    return 0;
}