#pragma once

#include <iostream>
using std::cout, std::endl;

template<class T>
class MyArray{
public:
    //构造函数
    MyArray(int capacity){
        m_Capacity = capacity;
        m_Size = 0;
        pAddress = new T[capacity];
    }

    //拷贝构造
    MyArray(const MyArray& arr){
        m_Capacity = arr.m_Capacity;
        m_Size = arr.m_Size;
        pAddress = new T[arr.m_Capacity];
        for(int i=0;i<arr.m_Size;++i){
            pAddress[i] = arr.pAddress[i];
        }
    }

    //拷贝赋值   
    //重载= 操作符  防止浅拷贝问题
    /*因为这里不是构造函数(不是重新构造)，所以要先对已存在的进行判断*/
    MyArray& operator=(const MyArray& arr){
        if(this != &arr){
            delete[] pAddress;
            m_Capacity=arr.m_Capacity;
            m_Size=arr.m_Size;
            pAddress = new T[m_Capacity];
            for(int i=0;i<arr.m_Size;++i){
                pAddress[i] = arr.pAddress[i];
            }
        }
        return *this;
    }

    //移动赋值
    MyArray& operator()(MyArray&& arr){
        if(this != &arr){
            delete[] pAddress;
            m_Capacity = arr.m_Capacity;
            m_Size = arr.m_Size;
            pAddress = arr.pAddress;
            arr.pAddress = nullptr;
        }
        return *this;
    }

    //析构函数
    ~MyArray(){
        if(pAddress!=nullptr){
            delete[] pAddress;
            pAddress=nullptr;
            m_Capacity=0;
            m_Size=0;
        }
    }

    int getCapacity(){
        return m_Capacity;
    }
    int getSize(){
        return m_Size;
    }

    //重载[] 操作符
    T& operator[](int index){
        if (index < 0 || index >= m_Size) {
            // 处理越界情况，这里可以抛出异常或者采取其他合适的措施
            throw std::out_of_range("Index out of range");
        }
        return pAddress[index]; 
    }

    void push_back(T val){
        if(m_Size==m_Capacity)
            return;
        pAddress[m_Size]=val;
        m_Size++;
    }

    void pop_back(){
        if(m_Size==0)
            return;
        m_Size--;
    }



private:
    int m_Capacity;
    int m_Size;
    T* pAddress;  //指向一个堆空间，这个空间存储真正的数据
};


