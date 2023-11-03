/*
学习了：template模板； 模板特化； 模板继承；this；
    其中：模板继承中，在子类中不能直接调用父类的方法；因为可能有模板特化的存在，使得有些父类不具有一些方法，所以编译器不会去父类中寻找方法；
         因此可以使用this->  或者 using声明式 在子类中来调用父类的方法（如果父类中有此方法）。  （这里说的是在子类中，而子类创建的对象可以直接调用父类的方法）
    对于this：只能在成员函数内使用；
    关于this详解：this指针通常用于在类的成员函数内部访问当前对象的成员变量和方法。
                 this指针指向调用该成员函数的对象的地址。通常，你只能在类的成员函数内部使用this指针来访问对象的成员。
                 在类的public部分直接使用this指针是不合法的。
*/

#include <iostream>
using namespace std;

class CompanyA{
public:
    //CompanyA(){cout<<"CompanyA construct"<<endl;}
    void SendCleartext(){cout << "CompanyA SendCleartext"<< endl;}
    void SendEncrypted(){cout << "CompanyA SendEncrypted"<< endl;}
};

class CompanyB{
public:
    //CompanyB(){cout<<"CompanyB construct"<<endl;}
    void SendCleartext(){cout << "CompanyB SendCleartext"<< endl;}
    void SendEncrypted(){cout << "CompanyB SendEncrypted"<< endl;}
};


class CompanyZ{
public:
    void SendEncrypted(){cout << "CompanyZ SendEncrypted"<< endl;}
};


template<typename Company>
class MsgSender{
public:
    Company C;
    void SendClear(){
        cout << "MsgSender SendClear" << endl;
        C.SendCleartext();
    }
    void SendSecret(){
        cout << "MsgSender SendSecret" << endl;
        C.SendEncrypted();
    }
};

//全特化版本；
//CompanyZ只提供一个方法
template<>
class MsgSender<CompanyZ>{
public:
    CompanyZ Z;
    void SendSecret(){
        cout << "MsgSender SendSecret" << endl;
        Z.SendEncrypted();
    }
};

//模板继承
template<typename Company>
class LoggingMsgSender : public MsgSender<Company>{
public:
    //调用模板基类的方法：
    using MsgSender<Company>::SendClear; // 方法1：使用using声明；（声明在函数外部）

    void SendClearMsg(){
        cout << "LoggingMsgSender SendClearMsg" << endl;
        SendClear();

        // this->SendClear();   //方法2：使用this->
        //发现： 只有在函数里面才会有this，自己的理解：只有对象才调用函数，this指的是这个对象；  
    }
    //在函数外部没有this
    // void test(){
    //     this->SendClearMsg();
    // }
};



int main(int argc, const char* argv[])
{
    MsgSender<CompanyA> MsgA;
    MsgA.SendClear();
    MsgSender<CompanyB> MsgB;
    MsgB.SendSecret();
    MsgSender<CompanyZ> MsgZ;
    MsgZ.SendSecret(); //只有这一个方法可以调用；

    LoggingMsgSender<CompanyB> Log;
    Log.SendClearMsg();
    //Log.test();


    return 0;
}