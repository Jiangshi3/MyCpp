/*
类模板特化-数组
*/
#include <iostream>
#include <cstring>
using namespace std;

#define Maxsize 5
//使用const和enum来代替#define
//const int Maxsize = 5; 
// enum{Maxsize = 5};

template<class T>
class Array{
private:
    T array[Maxsize];

public:
    Array(){
        for(int i=0;i<Maxsize;++i)
            array[i]=0;
    }
    T& operator[](int index);
    void sort();
};

//重载[]
template<class T>
T& Array<T>::operator[](int index){
    if(index<0||index>Maxsize-1){
        cout << "index error"<<endl;
        exit(0);
    }
    return array[index];
}

//整数的sort()     默认的sort，下面有对char的特化，如果是int就直接用此版本；
template<class T>
void Array<T>::sort(){
    int p,j;
    for(int i=0; i<Maxsize-1; ++i){  //这里是i<Maxsize-1;  
        p=i, j=i+1;
        for(; j<Maxsize; ++j){       //这里是j<Maxsize
            if(array[p]<array[j]){
                p=j;
            }
        }
        T temp = array[i];
        array[i]=array[p];
        array[p]=temp;
    }
}

//字符的sort()   这里是特化版本，如果是char的sort，就用此特化
template<>
void Array<char*>::sort(){
    int p, j;
    for(int i=0; i<Maxsize-1; ++i){  
        p=i, j=i+1;
        for(; j<Maxsize; ++j){
            if(strcmp(array[p], array[j])<0){
                p=j;
            }
        }
        char* temp = array[i];
        array[i] = array[p];
        array[p] = temp;
    }
}


int main(int argc, const char* argv[])
{
    Array<int> a1;
    Array<char*> b1;
    a1[0] = 1;
    a1[1] = 23;
    a1[2] = 6;
    a1[3] = 3;
    a1[4] = 9;
    a1.sort();
    for (int i = 0; i < 5; i++)
        cout << a1[i] << "\t";
    cout << endl;
    b1[0] = "x1";
    b1[1] = "ya";
    b1[2] = "ad";
    b1[3] = "be";
    b1[4] = "bc";
    b1.sort();
    for (int i = 0; i < 5; i++)
        cout << b1[i] << "\t";
    cout << endl;


    return 0;
}



