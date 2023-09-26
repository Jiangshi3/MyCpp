/*
如果基类的构造函数有参数，那么在派生类中创建对象时，需要先调用基类的构造函数
*/
#include <iostream>
#include <cstring>
using namespace std;

class Employer{
private:
    char Name[20];
    char Id[20];
public:
    Employer(const char* name, const char* id){
        strcpy(Name, name);
        strcpy(Id, id);
    }
    char* getName(){return Name;};
    char* getId(){return Id;};
    void display(){
        cout << Name << "\t" << Id << endl;
    }
};

class Manager:public Employer{
private:
    int WeekSalary;
public:
    //直接调用构造方法传递，基类构造方法有参数，派生类必须通过构造方法，在初始化列表中传递参数
    Manager(const char* name, const char* id, int week):Employer(name, id){
        WeekSalary = week * 1000;
  }
  void display() {
    cout << "经理：" << getName() << "\t" << getId() << "\t" << WeekSalary << endl;
  }
};

class SalaWorker:public Employer{
private:
    float baseMoney = 800.0;
    float workerMoney;
public:
    SalaWorker(const char* name, const char* id, int profit,int x):Employer(name, id){
        workerMoney = baseMoney + x * 0.05 * profit;
  }
  void display() {
    cout << "销售员：" << getName() << "\t" << getId() << "\t" << workerMoney << endl;
  }
};



int main(int argc, const char* argv[])
{
    int week=10;
    Manager m("小王", "111111", week);
    m.display();

    int profit=10;
    int x=100;
    SalaWorker s("小李", "222222", profit, x);
    s.display();

    return 0;
}