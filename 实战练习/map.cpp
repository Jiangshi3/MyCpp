/*
map的插入make_pair和pair和数组插入
map的查找： strcmp()==0
map的删除 erase(iter);
*/

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(int argc, const char* argv[])
{
    map<const char* , const char*> mp;
    map<const char* , const char*>::iterator iter;  //***迭代器
    // 注意这里构建的数组
    const char key[3][20] = {"img", "system", "ip"};
    const char value[3][20] = {"d:/a.img", "win7", "193.68.6.3"};
    cout << "key[0]=" << key[0] << endl;
    cout << "value[0]=" << value[0] << endl;

    cout << "------insert----------" << endl;
    //map.insert();以make_pair()插值
    for(int i=0;i<=2;++i){
        mp.insert(make_pair(key[i], value[i]));
    }
    //map.insert();以pair()插值
    mp.insert(pair<const char*, const char*>(key[2], value[2]));  //这里map的key不重复，所以原本就已经有了key[2]
    //数组插入
    mp["contry"]="China";


    //输出map
    cout << "--------print------" << endl;
    for(iter=mp.begin();iter!=mp.end();++iter){
        cout << iter->first << " -> " << iter->second << endl;
    }

    //查找
    char key1 [20] = "ip";
    for(iter=mp.begin();iter!=mp.end();++iter){
        if(strcmp(iter->first, key1)==0){
            cout << "find " << iter->first << "-->" << iter->second << endl;
        }
    }

    //删除 方法1 find
    iter = mp.find("ip");
    if(iter != mp.end()){
        cout << "erase key:" << iter->first << " -> " << iter->second << endl;
        mp.erase(iter);
    }
    // 删除 方法2 
    //按照key删除元素
    char drop_key[20] = "system";
    for(iter=mp.begin();iter!=mp.end();++iter){
        if(strcmp(iter->first, drop_key)==0){
            cout << "erase key:" << iter->first << " -> " << iter->second << endl;
            mp.erase(iter);
        }
    }

    //输出map
    cout << "--------print------" << endl;
    for(iter=mp.begin();iter!=mp.end();++iter){
        cout << iter->first << " -> " << iter->second << endl;
    }


    return 0;
}