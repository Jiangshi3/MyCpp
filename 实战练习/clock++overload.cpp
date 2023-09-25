#include <iostream>
using namespace std;

class Clock{
private:
    int Hour, Minute, Second;
public:
    Clock(int H=0, int M=0, int S=0);
    void ShowTime();
    Clock& operator++();
    Clock operator++(int);  // 后缀递增运算符时通常不返回引用; 后缀递增运算符应该返回递增之前的值的副本，而不是递增之后的值的引用。
};

Clock::Clock(int H, int M, int S){
    if(H>=0&&H<24 && M>=0&&M<60 && S>=0&&S<60){
        Hour=H;
        Minute=M;
        Second=S;
    }
    else
        cout << "Time input error!" << endl;
}
void Clock::ShowTime(){
    cout << Hour << ":" << Minute << ":" << Second << endl;
}
//时间递增一秒（重载前缀++运算符）
Clock& Clock::operator++(){
    Second++;
    if(Second>=60){
        Second=0;
        Minute++;
        if(Minute>=60){
            Minute=0;
            Hour++;
            if(Hour>=24){
                Hour=0;
            }
        }
    }
    return *this;
}
//时间递增一秒（重载后缀++运算符）
Clock Clock::operator++(int){
    Clock temp=*this;  // 创建一个临时副本以供后缀递增使用
    ++(*this);         //调用前缀递增运算符重载
    return temp;       // 返回临时副本，即递增之前的值
}




int main(int argc,const char* argv[])
{
    Clock time1(23, 59, 58);
    ++time1;  //使用前缀递增运算符
    Clock temp = time1++; //使用后缀运算符
    temp.ShowTime();      //显示递增前的时间
    time1.ShowTime();     //显示递增后的时间
    
    return 0;
}