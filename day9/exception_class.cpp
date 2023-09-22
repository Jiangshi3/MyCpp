/*try catch*/
#include <iostream>
using namespace std;

const int MAX = 3;
//  堆栈满时抛出的异常类
class Full{
private:
    int a;
public:
    Full(int x):a(x){};
    int getValue(){return a;}
};
class Empty{};  //  堆栈空时抛出的异常类
class Stack{
private:
    int top;
    int s[MAX];
public:
    Stack(){
        cout << "Stack Construct!"<<endl;
        top=-1;};
    void push(int x);
    int pop();
    void show();
};
void Stack::push(int x){
    if(top>=MAX-1){
        throw Full(x);
    }
    s[++top] = x;
}
int Stack::pop(){
    if(top<0){
        throw Empty();
    }
    return s[top--];
}
void Stack::show(){
    for(int i=0; i<=MAX-1; ++i){
        cout << s[i] << "\t";
    }
    
}

int main(int argc, const char* argv[])
{
    Stack s;
    try{
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4); // 将产生栈满异常
        s.show();
        s.pop();
        s.pop();
        s.pop();
        //s.pop();  // 将产生栈空异常
    }catch(Full e){
        cout << "Exception: Stack Full" << endl;
        cout << "The value not push in stack:" << e.getValue() << endl;
    }catch(Empty){
        cout << "Exception: Stack Empty" << endl;
    }

    return 0;
}