/*
vec.size()
vec.resize()
.empty()
push_back();
pop_back();
erase();
clear();
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{

    //vector<typename> vt;
    vector<int> vec;    //默认是0
    //vec.resize(5);    // 0 0 0 0 0
    vec.resize(5, 1);   // 1  1  1  1  1
    //vec.resize(10);     // 1  1  1  1  1  0  0  0  0  0  

    //vector<typename> vt(n_elem);
    //vector<int> vec(5);  // 0 0 0 0 0
    //现在已经初始化5个0后，没法再用resize()改变内容了；可以改变大小；

    vector<int> vec1 = {1, 2, 3, 4, 5};  // 使用初始化列表创建 vector

/*添加元素*/
    vec1.push_back(99);

/*访问 vector 的元素*/
    int elem = vec1[0];
    int elem1 = vec1.at(1);
    cout << "elem=" << elem << "  elem1=" << elem1 << endl;
/*获取 vector 的大小*/
    int size = vec1.size();

/*遍历*/
    for(auto& elem:vec1){
        elem*=2;
    }
    for(const auto& elem:vec1){
        cout << elem << "   ";
    }
    cout << endl;

/*删除 vector 中的元素*/
    vec1.pop_back();              // 删除末尾元素
    vec1.erase(vec1.begin()+2);   // 删除第三个元素

/*清空*/
    vec1.clear();

/*检查是否为空*/
    bool IsEmpty = vec1.empty();
    cout << "is empty: " << IsEmpty << endl;


    for(int i=0;i<vec1.size();++i){
        cout<< vec1[i] << "  " ;
    }

    return 0;
}

