/*
    自己在类中定义拷贝构造和拷贝赋值，一定要把所有成分都赋值；
    派生类复制函数必须调用相应的基类函数
*/

#include <iostream>
using namespace std;

void logCall(const string& log){
    cout << log << endl;
}

class Date{
public:
    Date(){}
    Date(int d):day(d){}
    int getDate(){
        return day;
    }

private:
    int day=0;
};

class customer{
public:
    customer(){}
    customer(string s, Date d) : name(s), lastTransaction(d){}
    customer(const customer& rhs) : name(rhs.name), lastTransaction(rhs.lastTransaction)
    {
        logCall("customer(const customer& rhs)");
    }
    customer& operator=(const customer& rhs)
    {
        logCall("customer& operator=(const customer& rhs)");
        this->name=rhs.name;
        this->lastTransaction = rhs.lastTransaction;
        return *this;
    }
    void setname(string s){
        this->name = s;
    }
    void setDate(Date d){
        lastTransaction = d;
    }
    void show(){
        cout << "name: " << name << "  Date:" << lastTransaction.getDate() << endl;
    }

private:
    string name;
    Date lastTransaction;
};


class PriorityCustomer : public customer{
public:
    PriorityCustomer(){}
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
    void setPriority(int p){priority=p;}
    void showPriority(){
        cout << "Priority:" << priority << "    ";
        customer::show();
    }
private:
    int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
    : customer(rhs),   // 调用基类的拷贝构造
    priority(rhs.priority)
{
    logCall("PriorityCustomer copy constructor");
}
PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    logCall("PriorityCustomer copy assignment");
    customer::operator=(rhs);  // 调用基类的拷贝赋值
    this->priority = rhs.priority;
    return *this;
}


int main(){
    Date D(28);
    // customer A("Tom", D);
    // customer B(A);  // 调用自己写的拷贝构造
    // customer C;
    // C=A;            // 调用自己写的拷贝赋值

    // A.show();
    // B.show();
    // C.show();


    PriorityCustomer pc1;
    pc1.setname("A");
    pc1.setDate(D);
    pc1.setPriority(100);
    PriorityCustomer pc2(pc1);
    PriorityCustomer pc3;
    pc3=pc1;
    pc1.showPriority();
    pc2.showPriority();
    pc3.showPriority();

    return 0;
}