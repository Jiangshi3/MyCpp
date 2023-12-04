#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class Investment{
public:
    Investment(){
        cout << "Investment constructor\n";
    }
    ~Investment(){
        cout << "Investment destructor\n";
    }
private:
    // data

};
Investment* createInvesment(){
    return new Investment();
}

void func(){
    std::shared_ptr<Investment> ptr1(createInvesment());
    std::shared_ptr<Investment> ptr2;
    ptr2 = ptr1;
}

int main()
{
    func();  // 只调用一次构造 一次析构函数 

    return 0;
}