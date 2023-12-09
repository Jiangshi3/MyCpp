/*
    pass by value 会导致切割问题
*/
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(){}
    Person(string name):_name{name}{}
    virtual void print() const{cout << "Person name: " << _name << endl;}
private:
    string _name="Zhangsan";
};

class Student : public Person{
public:
    Student(){}
    Student(string name):Person(name){}
    void print() const override{cout << "Student name: " << _name << endl;}

private:
    string _name="Xiaoli";
};

// void Display(Person p)  // 会导致切割问题
// {
//     p.print();
// }

void Display(const Person& p)
{
    p.print();
}

int main()
{
    Person p;
    Student s;
    Display(p);
    Display(s);

    return 0;
}