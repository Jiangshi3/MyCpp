#include <iostream>
#include <map>
using namespace std;
#include <typeinfo>

int main() {
	map<int, int> coll;
	decltype(coll)::value_type elem;


    return 0;
}
