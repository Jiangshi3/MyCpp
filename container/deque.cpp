/* 方法和vector差不多
.push_back();
.push_front();

.pop_back();
.pop_front();

.size();
.empty();
*/

#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char* argv[]){

//初始化init  
    std::deque<int> myDeque; // 创建一个空的双端队列
    std::deque<int> myDeque2(5); // 创建一个包含 5 个默认初始化值的双端队列
    std::deque<int> myDeque3 = {1, 2, 3, 4, 5}; // 使用初始化列表创建双端队列

/*添加元素*/
    myDeque.push_back(42); // 在尾部添加元素
    myDeque.push_front(10); // 在头部添加元素

/*访问*/
    int element = myDeque[0]; // 访问第一个元素
    int element2 = myDeque.at(1); // 访问第二个元素

/*大小*/
    int size = myDeque.size();

/*遍历*/
    for (int i = 0; i < myDeque.size(); ++i) {
        std::cout << myDeque[i] << " ";
    }

    // 或者使用 C++11 的范围循环
    for (const auto& element : myDeque) {
        std::cout << element << " ";
    }

/*删除头、尾元素*/
    myDeque.pop_back(); // 删除尾部元素
    myDeque.pop_front(); // 删除头部元素

myDeque.clear();
bool isEmpty = myDeque.empty();
std::deque<int> copyDeque = myDeque; // 创建一个拷贝

    return 0;
}