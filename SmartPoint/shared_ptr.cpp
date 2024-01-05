/*
    shared_ptr 和删除器
    .use_count() 显示引用计数的值

*/
#include <iostream>
#include <memory>
using namespace std;

class AA
{
public:
    AA(){cout << "constructor AA() " << endl;};
    AA(const string& name):m_name(name){cout << "constructor AA(" << m_name << ")" << endl;};
    ~AA(){cout << "destructor AA(" << m_name << ") " << endl;};
    string& get_name(){return m_name;};
private:
    string m_name;
};

// 删除器，普通函数
void deletefunc(AA* a)
{
    cout << "deletefunc(AA* a) " << endl;
    delete a;
}

// 删除器，仿函数
// struct deleteclass
class deleteclass 
{
public:
    void operator()(AA* a){
        cout << "class deleteclass " << endl;
        delete a;
    }
};

// 删除器, Lambda表达式
auto deletelamb=[](AA* a){
    cout << "deletelamb" << endl;
    delete a;
};


int main(int argc, char* argv[])
{
    
    // AA* p0 = new AA("Tom");
    // shared_ptr<AA> p1(new AA("Tom"));
    shared_ptr<AA> p1 = make_shared<AA>("Tom");
    shared_ptr<AA> p2=p1;
    shared_ptr<AA> p3=p1;
    cout << p1->get_name() << endl;
    cout << ".use_count()= " << p2.use_count() << endl;
    

    // shared_ptr<AA> p1(new AA("Tom")); // 用缺省的删除器
    // shared_ptr<AA> p1(new AA("Tom"), deletefunc);  // 删除器，普通函数
    // shared_ptr<AA> p1(new AA("Tom"), deleteclass()); 
    // shared_ptr<AA> p1(new AA("Tom"), deletelamb);  // 删除器, Lambda表达式

    // 给unique_ptr指定删除器
    // unique_ptr<AA, decltype(deletefunc)*> pu1(new AA("Jery"), deletefunc);
    // unique_ptr<AA, void(*)(AA*)> pu1(new AA("Jery"), deletefunc);
    // unique_ptr<AA, deleteclass> pu1(new AA("Jery"), deleteclass());
    // unique_ptr<AA, decltype(deletelamb)> pu1(new AA("Jery"), deletelamb);


    return 0;
}

