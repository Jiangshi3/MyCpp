/*
    unique_ptr
    不要用同一个裸指针初始化多个unique_ptr;
    使用get()方法返回裸指针；  
    unique_ptr作为参数要传引用（不能传值，因为unique_ptr没有拷贝构造函数）；
    unique_ptr不支持指针的运算（+，-，++，--）;
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

void func(unique_ptr<AA>& pp);

int main(int argc, char* argv[])
{
    AA* p=new AA("Jery");
    // unique_ptr<AA> pu1(p);
    // unique_ptr<AA> p0 = make_unique<AA>("Tony"); // C++14标准        初始化
    unique_ptr<AA> pu1(new AA("Tom"));
    cout << "m_name: " << pu1->get_name() << endl;
    cout << "m_name: " << (*pu1).get_name() << endl;

    // unique_ptr<AA> p0 = p;    // 非法
    // unique_ptr<AA> pu2(pu1);  // 非法，unique_ptr类中的拷贝构造函数=delete；

    // unique_ptr<AA> pu3;
    // pu3=pu1;                  // 非法，不能使用=对unique_ptr赋值； 已删除

    // 使用get()方法返回裸指针
    unique_ptr<AA> pu4(p);
    cout << "p=" << p << endl;
    cout << "pu4.get()=" << pu4.get() << endl;
    cout << "&pu4=" << &pu4 << endl;

    func(pu4);


    return 0;
}

// unique_ptr作为参数要传引用
void func(unique_ptr<AA>& pp)
{
    cout << "func: pp->m_name=" << pp->get_name() << endl;
}
