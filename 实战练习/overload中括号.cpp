/*
通过重载[]运算符，您可以让类的对象支持使用[]来访问其成员数据或执行其他自定义操作
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Person{
    double salary;
    char* name;
};

class SalaryManage{
private:
    Person* employ; //存放职工信息的数组
    int max;   // 数组下标上界
    int n;     // 数据实际职工人数
public:
    SalaryManage(int MAX=0) : max(MAX)
    {
        n=0;
        employ = new Person[max];
    }
    double& operator[](char* Name){  //重载[]，返回引用
        Person* p;
        for(p=employ;p<employ+n;++p){
            //如果找到对应的
            if (strcmp(p->name, Name)==0)
            {
                return p->salary;
            }           
        }
        //如果不存在，就添加
        p=employ+n;
        n++;
        p->name = new char[strlen(Name)+1];
        strcpy(p->name, Name);
        p->salary=0;
        return p->salary;
    }

    void display(){
        for(int i=0;i<n;++i){
            cout << employ[i].name << " ---> " << employ[i].salary << endl;
        }
    }
    ~SalaryManage(){delete[] employ;}
};

int main(int artc, const char* argv[])
{
    SalaryManage s(3);
    s["Tom"] = 2188.88;
    s["Jery"] = 1230.07;
    s["jia"] = 3200.97;
    cout << "Tom\t" << s["Tom"] << endl;
    cout << "Jery\t" << s["Jery"] << endl;
    cout << "jia\t" << s["jia"] << endl;

    cout << "-------display--------\n\n";
    s.display();

    return 0;
}