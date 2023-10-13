
#include <iostream>
#include <list>
#include <vector>
#include<algorithm>
using namespace std;

int main(int argc, const char* argv[])
{

    list<int> l1{2,4,5};
    list<int>::iterator ite;
    ite = find(l1.begin(), l1.end(), 2);
    auto ite1 = find(l1.begin(), l1.end(), 4);

    vector<int> vec{1, 2, 3, 4, 5};
    for(auto &elem:vec){  // pass by reference
        elem *= 2;
    }

    for(auto elem:vec){   // pass by value
        cout << elem << '\t';
    }

    return 0;
}