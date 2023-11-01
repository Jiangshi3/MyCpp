/*
目的：手写实现一个哈希表，采用拉链法构建，每个hash(key)对应的是一个红黑树。
简易版哈希表；
将哈希表封装在一个类中,完成遍历的定义与声明以及构造、析构的实现：
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename Key, typename Value>
class HashTable{
private:
    const static int upperTol = 3;
    const static int lowerTol = 1;
    const static int initCapacity = 1;  //初始容量
    map<Key, Value> **hashtable;  //指针数组
    int M;  // M可以表示有几条链
    int size;
public:
    /**
     * 传参构造
     * @param M
     */
    HashTable(int M) : M(M), size(0){
        this->hashtable = new map<Key, Value> *[M];  //创建了一个指向 map<Key, Value> 类型的指针数组，其中数组的大小由 M 决定
        for(int i=0;i<M;++i){
            this->hashtable[i]=new map<Key, Value>;
        }
    }
    /**
    *默认构造
    */
    HashTable(){
        HashTable(initCapacity);  // 默认构造调用传参构造，参数大小为initCapacity
    }
    /**
     * 析构函数
     */
    ~HashTable(){
        free(M);
    }
private:
    /**
     * 释放内存
     */
    void free(int M){
        for(int i=0;i<M;++i){
            if(hashtable[i]){
                delete hashtable[i];
            }
        }
        delete[] hashtable;
    } 

public:
    /**
     * 哈希函数
     * @param key
     * @return
    */
    int hashFunc(Key key){
        std::hash<Key> h;
        return (h(key)&0x7fffffff) % M; 
        //使用std的hash得到值之后，将其&上0x7fffffff，去掉高位的负号，转为正数，然后余上M。
    }
    /*实现增删改查*/
    void add(Key key, Value value);  //声明； 在类外定义

    /**
     *  移除key
     *  @param key
     *  @return 0 success -1 fail
    */
    Value remove(Key key){
        Value res=-1;
        if(contains(key)){
            hashtable[hashFunc(key)]->erase(key);
            size--;
            res=0;
            if(size<minCapacity() && M/2>=initCapacity)
                resize(M/2);
        }
        return res;
    }

    /**
     * 重设key对应的value
     * @param key
     * @param value
    */
    void set(Key key, Value value){
        if(!contains(key))
            throw "key not exists!";
        //key存在的话，修改value
        hashtable[hashFunc(key)]->erase(key);
        hashtable[hashFunc(key)]->insert(make_pair(key, value));
    }     

    /**
     * 获取key对应的value
     * @param key
     * @return
    */
    Value get(Key key) {
        if (contains(key))
            return hashtable[hashFunc(key)]->at(key);
        return 0;
    }

    /**
     * 判断key是否存在
     * @param key
     * @return
    */
    bool contains(Key key) {
        return hashtable[hashFunc(key)] == NULL || this->hashtable[hashFunc(key)]->count(key) == 0 ? false : true;
    }
    /**
    * 获取哈希表元素个数
    * @return
    */
    int getSize(){
        return size;
    }

    /**
    * 最大容量
    * @return
    */
    Value maxCapacity(){
        return M*upperTol;
    }
    /**
    * 最小容量
    * @return
    */
    Value minCapacity(){
        return M*lowerTol;
    }

    //resize(); 完成动态调整内存，将原来内存中的内容拷贝到新分配的空间，释放原空间！
    /**
    * 动态调整内存,保证时间复杂度O(1)查找
    * 把扩容后的操作,平摊到前面每次操作,时间复杂度O(2),那就是O(1)了
    * @param newM
    */
    void resize(int newM){
        cout << "resize " << newM << endl;
        map<Key, Value> **newHashTable = new map<Key, Value> *[newM];
        for(int i=0;i<newM;++i){
            newHashTable[i] = new map<Key, Value>;
        }
        int oldM = M;
        this->M=newM;
        for(int i=0;i<oldM;++i){
            map<Key, Value> m = *(hashtable[i]);
            for(auto p:m){
                newHashTable[hashFunc(p.first)] -> insert(make_pair(p.first, p.second));
            }
        }
        free(oldM);
        this->hashtable = newHashTable;
    }

    void print() const{
        for(int i=0;i<M;++i){
            map<Key, Value> m = *(hashtable[i]);
            for(const auto& p:m){
                cout << p.first << ":" << p.second << "   ";
            }
        }
        cout << endl;

    }

private:
    template<typename K, typename V>
    //重载<< 操作符
    friend ostream &operator<<(ostream &out, HashTable<K, V> &hashTable);  //声明

};

//增操作； 底层采用的是红黑树，使用insert方法； 
//         因为key不可以重复，对于重复的key采用insert没有效果，因此如果要修改对应的value，可以通过[ ], 也可以先删除，再插入，这里就采用这个方法。
/**
 * 添加新元素
 * @param key
 * @param value
*/
template <typename Key, typename Value>
void HashTable<Key, Value>::add(Key key, Value value){
    // 拉链法出来的map如果为空,就动态分配一个map,然后进行插入
    // 如果key不存在就看内存是否存在,不存在,就分配,存在就插入
    if(hashtable[hashFunc(key)]==NULL || hashtable[hashFunc(key)]->count(key)==0){
        if(hashtable[hashFunc(key)]==NULL)
            hashtable[hashFunc(key)] = new map<Key, Value>;
         hashtable[hashFunc(key)]->insert(make_pair(key, value));
         size++;  // 如果添加要增加size
         if(size >= maxCapacity())
            resize(2*M);
    }
    else{
        //如果存在key，则修改对应的value
        hashtable[hashFunc(key)]->erase(key);
        hashtable[hashFunc(key)]->insert(make_pair(key, value));
    }
}

template<typename K, typename V>
ostream &operator<<(ostream &out, HashTable<K, V> &hashTable) {  //定义
    hashTable.print();
    return out;
}



int main(){
    cout << "hello hash" << endl;
    /*测试*/
    vector<string> words{"java", "c++", "c", "c++", "c#", "python", "ruby", "python",
                         "c", "c", "c++", "java", "c++", "rust", "python"};
    HashTable<string, int> ht(1);

    for (string word : words) {
        if (ht.contains(word)) {
            ht.set(word, ht.get(word) + 1);
        } else {
            ht.add(word, 1);
        }
    }
    cout<<ht;
    cout<<"size="<<ht.getSize()<<",maxCapacity="<<ht.maxCapacity()<<",minCapacity="<<ht.minCapacity()<<endl;
    string w="c++";
    ht.remove(w);
    if (ht.contains(w))
        cout << "" << w << ": " << ht.get(w) << endl;
    else
        cout << "No word " << w << " in words" << endl;
    cout<<ht;
    ht.remove("c#");
    ht.remove("java");
    ht.remove("c");
    cout<<"size="<<ht.getSize()<<", maxCapacity="<<ht.maxCapacity()<<", minCapacity="<<ht.minCapacity()<<endl;
    cout<<ht;

    return 0;
}
