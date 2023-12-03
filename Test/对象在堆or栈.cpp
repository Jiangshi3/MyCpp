//对象产生于堆中； 将析构函数声明为私有
#include <iostream>
using namespace std;

class HeapOnly {
public:
    HeapOnly(){
        cout << "HeapOnly constructor" << endl;
    }
    // 提供静态成员函数用于在堆上创建对象
    static void deleteInstance(HeapOnly* obj) {
        delete obj;
    }
private:
    // 将构造函数声明为私有，防止在栈上直接创建对象
    ~HeapOnly() {
        cout << "HeapOnly destructor" << endl;
    }
};


int main() {
    // HeapOnly obj; // 会报错
    // 在堆上创建对象
    HeapOnly* obj = new HeapOnly;
    
    // 释放在堆上创建的对象
    HeapOnly::deleteInstance(obj);

    return 0;
}



#if 0
// 对象分配在栈上
class StackOnly {
public:
    // 构造函数和析构函数等其他成员函数
private:
    // 将operator new和operator delete声明为私有，阻止在堆上分配内存
    static void* operator new(std::size_t size);
    static void operator delete(void* ptr);
};

int main() {
    // 在栈上创建对象
    StackOnly stackObject;

    // 以下代码将导致编译错误，因为operator new是私有的，不能在堆上分配内存
    // StackOnly* heapObject = new StackOnly;
    return 0;
}
#endif
