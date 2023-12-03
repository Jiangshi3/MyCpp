/*
    类中const数据成员、引用数据成员
    特别是引用数据成员，必须用初始化列表初始化，而不能通过赋值初始化！
    使用初始化列表初始化const数据成员和引用数据成员是一种最佳实践，
    确保对象在创建时以正确的方式初始化，而不是在构造函数的函数体内部尝试对其进行赋值。
*/

#include <iostream>

class Animal {
public:
    Animal(int age,std::string name):age_(age),name_(name) {
        std::cout << "Animal(int age) is called" << std::endl;
    }
private:
    int &age_;
    const std::string name_;
};

int main() {
    Animal animal(10,"hh");
    return 0;
}


