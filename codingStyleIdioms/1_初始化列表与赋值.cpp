/*
    类之间的嵌套；
    组合而不是继承；
    结论：
        类中包含其他自定义的class或者struct，采用初始化列表，实际上就是创建对象同时并初始化
        而采用类中赋值方式，等价于先定义对象，再进行赋值，一般会先调用默认构造，再调用=操作符重载函数。
*/

#include <iostream>
using namespace std;

class Animal{
public:
    Animal(){
        cout << "Animal() construct" << endl;
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

class Dog{
public:
    Dog(){
        std::cout << "Dog() is called" << std::endl;
    }
    Dog(const Animal& animal) : __animal(animal) {
        // 这里直调用一个Animal的拷贝构造函数； Animal(const Animal&)
        std::cout << "Dog(const Animal &animal) is called" << std::endl;
    }

    // Dog(const Animal& animal){
    //     // 这种会调用一个Animal()构造函数，在调用一个Animal& operator=(const Aniaml&)的拷贝赋值
    //     __animal = animal;
    //     std::cout << "Dog(const Animal &animal) is called" << std::endl;
    // }
    ~Dog(){
        std::cout << "~Dog() is called" << std::endl;
    }

private:
    Animal __animal;
};

int main()
{
    Animal animal;
    Dog d(animal);

    return 0;
}

/* output:
    Animal() construct
    Animal(const Animal&) construct
    Dog(const Animal &animal) is called
    ~Dog() is called
    ~Animal() disconstruct
    ~Animal() disconstruct
*/
