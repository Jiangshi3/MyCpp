#include <iostream>
#include <list>
#include <array>
using namespace std;

int main(int argc, char* argv[])
{
/*list容器的创建；  其他容器也是这种init；*/

    //1、创建一个没有任何元素的空 list 容器：    和空 array 容器不同，空的 list 容器在创建之后仍可以添加元素，
    std::list<int> Mylist;

    //2、创建一个包含 n 个元素的 list 容器：
    std::list<int> Mylist(10);   // 其中包含 10 个元素，每个元素的值都为相应类型的默认值（int类型的默认值为 0）

    //3 创建一个包含 n 个元素的 list 容器，并为每个元素指定初始值
    list<int> Mylist(10, 5);   //创建了一个包含 10 个元素并且值都为 5 个 values 容器

    //4 已有 list 容器的情况下，通过拷贝该容器可以创建新的 list 容器
    list<int> Mylist1(Mylist);  //采用此方式，必须保证新旧容器存储的元素类型一致。

    //5 通过拷贝其他类型容器（或者普通数组）中指定区域内的元素，可以创建新的 list 容器
    int a[] = {1, 2, 3};
    list<int> MyCopylist(a, a+3);  //拷贝普通数组，创建list容器

    std::array<int, 5> arr{1, 2, 3, 4, 5};  //拷贝其它类型的容器，创建 list 容器
    std::list<int> MyCopylist1(arr.begin()+1, arr.end());  //拷贝arr容器中的{2, 3, 4, 5}


    return 0;
}