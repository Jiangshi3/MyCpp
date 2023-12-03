#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool func(const int& val1, const int& val2){
    return val1 > val2;
}

class Mycom{
public:
    bool operator()(const int& val1, const int& val2){
        return val1 > val2;
    }
};

void myprint_vec(const vector<int>& v){
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout << *it << " " ;
    }
    cout << endl;
}

int main(){
    vector<int> v{3, 2, 1, 4, 5};
    // sort(v.begin(), v.end(), func);

    // Mycom mycom;
    //sort(v.begin(), v.end(), mycom);
    
    sort(v.begin(), v.end(), Mycom());
    myprint_vec(v);

    return 0;
}