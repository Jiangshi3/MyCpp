#include <iostream>
using namespace std;

void func(int x){
    try{
        if(x==0)
            throw "异常";
    } catch(...){
        cout<<"in func"<<endl;
        throw 1;
    }
}

int main(int argc, char* argv[])
{
    try{
        func(0);
    }catch(int n){
        cout << "in main"<<endl;
    }
    cout << "end main"<< endl;

    return 0;
}