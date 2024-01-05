/*
    shared_ptr 和删除器
    .use_count() 显示引用计数的值

*/
#include <iostream>
#include <memory>
using namespace std;

class BB;

class AA
{
public:
    AA(){cout << "constructor AA() " << endl;};
    AA(const string& name):m_name(name){cout << "constructor AA(" << m_name << ")" << endl;};
    ~AA(){cout << "destructor AA(" << m_name << ") " << endl;};

    string m_name;
    weak_ptr<BB> m_p;
};

class BB
{
public:
    BB(){cout << "constructor BB() " << endl;};
    BB(const string& name):m_name(name){cout << "constructor BB(" << m_name << ")" << endl;};
    ~BB(){cout << "destructor BB(" << m_name << ") " << endl;};

    string m_name;
    weak_ptr<AA> m_p;
};



int main(int argc, char* argv[])
{

    shared_ptr<AA> p1 = make_shared<AA>("Tom");
    shared_ptr<BB> p2 = make_shared<BB>("Jery");
    p1->m_p = p2;
    p2->m_p = p1;

    return 0;
}

