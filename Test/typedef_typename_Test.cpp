/*在模板编程中使用 typename 和 typedef 创建类型别名
!!! 有“::”就要有typename，这告诉编译器是一个类型
*/

#include <iostream>
#include <vector>
using namespace std;

// 定义一个模板类，用于包装不同类型的容器
template <typename Container>
class ContainerWrapper{
public:
    // 使用typename定义一个类型别名，将Container类型的value_type命名为ValueType
    //typedef typename Container::value_type ValueType;  // √ ！！！
    typedef typename iterator_traits<typename Container::iterator>::value_type ValueType;  //！！！与上面实现相同，这个更复杂，更能结合之前学到的系统东西！功力深厚！
    // 每个container都有Iterator，通过萃取机iterator_traits得到其中五个typedef之一的value_type,再与typename和typedef结合使用；

    // 构造函数，接受一个容器并保存它
    ContainerWrapper(const Container& container):mycontainer(container){}

    // 打印容器中的元素
    void printElements(){
        for(const ValueType& elem:mycontainer){
            cout << elem << "  ";
        }
        cout << endl;
    }

private:
    Container mycontainer;

};


int main(int argc, const char* argv[])
{
    std::vector<int> intVector = {1, 2, 3, 4, 5};
    ContainerWrapper<std::vector<int>> intWrapper(intVector);
    intWrapper.printElements();

    vector<double> doubleVector{1.1, 2.2, 3.3, 4.4};
    ContainerWrapper<vector<double>> doubleWrapper(doubleVector);
    doubleWrapper.printElements();

    return 0;
}

