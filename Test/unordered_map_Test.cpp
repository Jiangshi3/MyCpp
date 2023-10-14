/*测试unordered_map
 底层实现是哈希表；
 直接使用的时候，不是所想的那种哈希冲突来解决，而是直接覆盖掉了； 也可以用来++，--*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, const char* argv[])
{
    unordered_map<int, int> map;
    map[1]++;
    map[1]++;
    map[1]++;
    auto it = map.find(1);
    cout << "it " << --(it->second) << endl;
    //--map[1];

    for(auto const &item:map){
        cout << item.first << " --- " << item.second << endl;
    }

cout << "------------" << endl;

    unordered_map<int, string> myMap;
    // 插入元素
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    myMap[4] = "Four";
    cout << "myMap.size() " << myMap.size() << endl;

    // myMap[1] = "NewOne";  // 覆盖掉
    int key=4;
    myMap.erase(key);
    auto iter=myMap.find(key);
    if(iter!=myMap.end())
    {
        cout << "find " << key << endl;        
    }else{
        cout << "not find " << key << endl;
    }
    myMap[5];
    

    for(auto const &item:myMap){
        cout << item.first << " --- " << item.second << endl;
    }
    return 0;
}



