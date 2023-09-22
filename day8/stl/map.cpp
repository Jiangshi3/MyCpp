#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(int argc, const char** argv[])
{
    string name[] = {"张三", "李四", "王五"};
    double salary[] = {1400, 2000, 8000};
    map<string, double> sal;
    map<string, double>::iterator p;
    for(int i=0;i<3;++i){
        sal.insert(make_pair(name[i], salary[i]));
    }
    sal["Tom"] = 9000;
    sal["Jery"] = 1008.6;
    for(p=sal.begin();p!=sal.end();++p){
        cout << p->first << " ---> " << p->second << endl;
    }

    string person = "Tom";
    int flag=0;
    for(p=sal.begin();p!=sal.end();++p){
        if(p->first==person){
            cout << "find " << person << " --> " << p->second << endl;
            flag=1;
            break;
        }        
    }
    if(!flag)
        cout << "no find " << person << endl;

    string delper = "Jery";
    map<string, double>::iterator it;
    it = sal.find(delper);
    if(it!=sal.end()){
        cout << "find " << (*it).first << " --> " << (*it).second << endl;
        sal.erase(it);
        cout << "erase " << (*it).first << endl;
    }

    cout << "now map"<< endl;
    for(p=sal.begin(); p!=sal.end(); ++p){
        cout << p->first << " --> " << p->second << "\t";
    }



    return 0;
}