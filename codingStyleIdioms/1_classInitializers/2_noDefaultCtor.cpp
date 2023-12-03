/*
    组合改为继承；
    基类中没有默认的构造函数，在子类中必须通过初始化列表给基类带参构造传递参数；
*/

#include <iostream>
using namespace std;

class Animal{
public:
    Animal(int age){
        cout << "Animal(int age) construct" << endl;
    }
    Animal(const Animal&){
        cout << "Animal(const Animal&) construct" << endl;
    }
    Animal& operator=(const Animal&){
        cout << "Animal& operator=(const Animal&) construct" << endl;
        return *this;
    }
    ~Animal(){
        cout << "~Animal() disconstruct" << endl;
    }
};

class Dog : public Animal{
public:
    // 在Animal中没有默认构造函数,这种就是错误的
    // Dog(int age){
    //     std::cout << "Dog(int age) is called" << std::endl;
    // }
    Dog(int age) : Animal(age){
        std::cout << "Dog(int age) is called" << std::endl;
    }
    ~Dog(){
        std::cout << "~Dog() is called" << std::endl;
    }
};

int main(){
    // Animal ani;
    Dog d(10);

    return 0;
}

