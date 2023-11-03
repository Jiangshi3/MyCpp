#include <iostream>
#include <typeinfo>
using namespace std;

class Base{
public:
    Base(int x=99):data_base(x){}
    void show(){cout << "Base::show()" << endl;};
    void show(int x) {cout << "Base::show(int)" << endl;}

protected:
    int data_base;
};

class Derive:public Base{
public:
    Derive(int x=100):Base(x), data_de(x){}
    void show(){cout << "Derive::show()" << endl;}

private:
    int data_de;
};


int main(){
    Derive d(50);
    Base* ptr = &d;
    // 静态(编译期间)的绑定(函数的调用)
    ptr->show();    // Base::show()  
    ptr->show(20);  // Base::show(int)

    cout << sizeof(Base) << endl;     // 4
    cout << sizeof(Derive) << endl;   // 8
    cout << typeid(ptr).name() << endl;  // class Base*
    cout << typeid(*ptr).name() << endl; // class Base

/*



*/


    return 0;
}