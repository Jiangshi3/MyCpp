#include <stdlib.h>
#include <string.h>
#include <iostream>

class xstring{
private:
    char* m_str;
    size_t m_len;
    size_t m_cap;

public:
    size_t len(){
        return m_len;
    }
    size_t cap(){
        return m_cap;
    }
public:
    // cout自定义的class 
    friend std::ostream& operator<<(std::ostream& os, const xstring& s) {
        return std::cout << s.m_str;
    }

public:
    xstring() = default;

    // 带参构造
    xstring(const char* s){
        if(s==nullptr){
            m_str=new char[1];
            if(m_str==nullptr)
                exit(-1);
            *m_str='\0';
            m_len=0;
            m_cap=0;
        }else{
            size_t len = strlen(s);
            m_str = new char[len+1];
            if(m_str==nullptr)
                exit(-1);
            strcpy(m_str, s);
            m_len = len;
            m_cap = len;
        }
    }

    //这里禁止隐士类型转换
    explicit xstring(const size_t cap){
        m_str = new char[cap+1];
        if(m_str==nullptr)
            exit(-1);
        m_cap = cap;
        m_len = 0;
    }

    //拷贝构造
    xstring(const xstring& s){
        //int len = s.m_len;
        int len = strlen(s.m_str);
        m_str = new char[len+1];
        if(m_str==nullptr)
            exit(-1);
        strcpy(m_str, s.m_str);
        m_cap = len;
        m_len = len;
    }

    // 移动构造
    // 一个临时对象的值移动到一个新的对象上
    // 一个对象创建另一个对象，但是创建后原对象不再使用
    // 使用转移构造函数可以避免内存拷贝的开销
    /*这里的临时对象（形参）不能是const，因为要修改形参*/
    xstring(xstring&& s){
        if(s.m_str!=nullptr){
            m_str=s.m_str;
            m_cap = s.m_cap;
            m_len = s.m_len;
            s.m_str = nullptr;
        }
    }

    //拷贝赋值
    xstring& operator=(const xstring& s){
        if(this!=&s){
            delete[] m_str;
            size_t len = strlen(s.m_str);
            if(m_cap<len){
                m_str=new char[len+1];
                m_len = len;
                m_cap = len;
            }else{
                memset(m_str, 0, len);  // 将一块内存区域的内容设置为指定的值
                m_len = len;
                m_cap = s.m_cap;
            }
            strcpy(m_str, s.m_str);
        }
        return *this;
    }

    // 移动赋值
    xstring& operator=(xstring&& s){
        if(this != &s){
            delete[] m_str;
            m_str = s.m_str;
            m_cap = s.m_cap;
            m_len = s.m_len;
            s.m_str = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~xstring(){
        delete[] m_str;
        m_str = nullptr;
    }



};
