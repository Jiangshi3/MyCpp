#include <iostream>
using namespace std;

class Base{
public:
    Base(){cout << "Base Construct" << endl;}
    //virtual void func(){cout << "Base func" << endl;}
    virtual void func()=0;
    virtual ~Base(){cout << "Base Destruct" << endl;}  //纯虚基类的析构函数应该声明为virtual，否则不能析构子类；
};

class Derived : public Base{
public: 
    Derived(){cout << "Derived Construct" << endl;}
    virtual void func() override{cout << "Derived func" << endl;}
    ~Derived(){cout << "Derived Destruct" << endl;}
};


int main(){
    // Base A;
    //Derived D;
    Base* a = new Derived;
    a->func();
    delete a;  //如果纯虚基类Base的析构函数不是virtual（第九行），那么这里delete不会调用子类的析构函数；a的类型是Base*，只能调用基类的析构函数；

    return 0;
}